//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int main()
{
    char str[MAX_SIZE];
    int i,j,k,len;
    char revStr[MAX_SIZE];
    char *token;
    char *copyStr;
    char *punctuation = "!@#$%^&*()_+-=[]{}|;:,.<>? ";

    printf("Enter a string: ");
    scanf("%s",str);

    // Removing Punctuations
    for(i=0;i<strlen(str);i++)
    {
        if(!isalnum(str[i]))
        {
            for(j=i;j<strlen(str);j++)
            {
                str[j] = str[j+1];
            }
            str[strlen(str)-1] = '\0';
            i--;
        }
    }

    // Reversing the string
    for(i=strlen(str)-1;i>=0;i--)
    {
        revStr[i] = str[i];
    }
    revStr[strlen(str)] = '\0';

    // Displaying the reversed string
    printf("\nReversed string: %s\n",revStr);

    // Tokenizing the string
    token = strtok(str," ");
    while(token!= NULL)
    {
        printf("%s ",token);
        token = strtok(NULL," ");
    }

    // Copying the string
    copyStr = (char*)malloc(strlen(str)+1);
    if(copyStr == NULL)
    {
        printf("\nMemory Error!\n");
        exit(0);
    }
    strcpy(copyStr,str);

    // Displaying the copied string
    printf("\nCopied string: %s\n",copyStr);

    // Concatenating two strings
    char str1[MAX_SIZE] = "Hello";
    char str2[MAX_SIZE] = " World";
    strcat(str1,str2);

    // Displaying the concatenated string
    printf("\nConcatenated string: %s\n",str1);

    // Comparing two strings
    char str3[MAX_SIZE] = "Hello";
    char str4[MAX_SIZE] = "Hello";
    if(strcmp(str3,str4) == 0)
    {
        printf("\nStrings are equal!\n");
    }
    else
    {
        printf("\nStrings are not equal!\n");
    }

    // Converting string to uppercase
    for(i=0;i<strlen(str);i++)
    {
        str[i] = toupper(str[i]);
    }

    // Displaying the uppercase string
    printf("\nUppercase string: %s\n",str);

    return 0;
}