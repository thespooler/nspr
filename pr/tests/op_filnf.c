/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* 
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Netscape security libraries.
 * 
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are 
 * Copyright (C) 1998-2000 Netscape Communications Corporation.  All
 * Rights Reserved.
 * 
 * Contributor(s):
 * 
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 or later (the
 * "GPL"), in which case the provisions of the GPL are applicable 
 * instead of those above.  If you wish to allow use of your 
 * version of this file only under the terms of the GPL and not to
 * allow others to use your version of this file under the MPL,
 * indicate your decision by deleting the provisions above and
 * replace them with the notice and other provisions required by
 * the GPL.  If you do not delete the provisions above, a recipient
 * may use your version of this file under either the MPL or the
 * GPL.
 */

/***********************************************************************
**
** Name: op_filnf.c
**
** Description: Test Program to verify the PR_FILE_NOT_FOUND_ERROR
**				This test program also uses the TRUNCATE option
**
** Modification History:
** 03-June-97 AGarcia- Initial version
***********************************************************************/

/***********************************************************************
** Includes
***********************************************************************/
/* Used to get the command line option */
#include "prinit.h"
#include "prmem.h"
#include "prio.h"
#include "prerror.h"
#include <stdio.h>
#include "plgetopt.h"

#ifdef XP_MAC
#include "prlog.h"
#define printf PR_LogPrint
#else
#endif

static PRFileDesc *t1;
PRIntn error_code;

int main(int argc, char **argv)
{


#ifdef XP_MAC
	SetupMacPrintfLog("pr_open_re.log");
#endif
	

    PR_STDIO_INIT();
	t1 = PR_Open("/usr/tmp/ttools/err03.tmp", PR_TRUNCATE | PR_RDWR, 0666);
	if (t1 == NULL) 
		if (PR_GetError() == PR_FILE_NOT_FOUND_ERROR) {
				printf ("error code is %d \n", PR_GetError());
				printf ("PASS\n");
				return 0;
		}
		else {
				printf ("error code is %d \n", PR_GetError());
				printf ("FAIL\n");
			return 1;
		}
}			
