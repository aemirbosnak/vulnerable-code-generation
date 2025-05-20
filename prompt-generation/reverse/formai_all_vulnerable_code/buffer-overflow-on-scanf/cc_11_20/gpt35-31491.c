//FormAI DATASET v1.0 Category: Spam Detection System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char email[1000];
    
    //Ask user to enter email
    printf("Enter your email: ");
    scanf("%s", email);
    
    int spamFlag = 0;
    
    //Checking for spam keywords in email
    if (strstr(email, "free") != NULL || strstr(email, "win") != NULL || strstr(email, "prize") != NULL || strstr(email, "lottery") != NULL)
    {
        spamFlag = 1;
    }
    
    //Checking for multiple exclamation marks in email
    char* p;
    int exclamationCount = 0;
    p = strchr(email,'!');
    
    while(p!=NULL)
    {
        exclamationCount++;
        p=strchr(p+1,'!');
    }
    
    if(exclamationCount > 3)
    {
        spamFlag = 1;
    }
    
    //Checking for suspicious link in email
    if(strstr(email, ".xyz") != NULL || strstr(email, ".top") != NULL || strstr(email, ".biz") != NULL)
    {
        spamFlag = 1;
    }
    
    //Checking for long words in email
    char* token = strtok(email, " ");
    while( token != NULL )
    {
        if(strlen(token) > 10)
        {
            spamFlag = 1;
            break;
        }
        token = strtok(NULL, " ");
    }
    
    //Printing out result
    if(spamFlag == 1)
    {
        printf("WARNING: This email is a spam message!\n");
    }
    else
    {
        printf("This email is not a spam message. Enjoy your inbox!\n");
    }
    
    return 0;
}