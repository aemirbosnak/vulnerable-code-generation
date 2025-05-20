//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    char input[100];
    bool isPalindrome = true;
    int i,j;

    //Taking input from user
    printf("Enter a string: ");
    scanf("%s",input);

    //Removing spaces and converting to lowercase
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' ')
        {
            input[i] = '\0';
        }
        else if(isalpha(input[i]))
        {
            input[i] = tolower(input[i]);
        }
    }

    //Checking for palindrome
    for(i=0,j=strlen(input)-1;i<j;i++,j--)
    {
        if(input[i]!=input[j])
        {
            isPalindrome = false;
            break;
        }
    }

    //Displaying result
    if(isPalindrome)
    {
        printf("The given string is a palindrome.\n");
    }
    else
    {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}