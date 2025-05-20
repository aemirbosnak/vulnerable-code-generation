//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isPalindrome(char *str);

int main()
{
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if(isPalindrome(input))
    {
        printf("%s is a palindrome.\n", input);
    }
    else
    {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}

int isPalindrome(char *str)
{
    int i, j;
    char cleanStr[100];
    int length = strlen(str);

    // Clean the string by removing non-alphanumeric characters and converting to lowercase
    for(i=0, j=0; i<length; i++)
    {
        if(isalnum(str[i]))
        {
            cleanStr[j] = tolower(str[i]);
            j++;
        }
    }

    // Compare the cleaned string with its reverse
    for(i=0, j=strlen(cleanStr)-1; i<j; i++, j--)
    {
        if(cleanStr[i]!= cleanStr[j])
        {
            return 0;
        }
    }

    return 1;
}