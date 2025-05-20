//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100



int isPalindrome(char str[])
{
    int i, j, len;
    char temp;
    len = strlen(str);
    for (i = 0; i < len / 2; i++)
    {
        j = len - i - 1;
        if (tolower(str[i])!= tolower(str[j]))
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    char str[MAX];
    int i, j;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (!isalpha(str[i]))
        {
            printf("Error: Invalid input. Only alphabets are allowed.\n");
            return;
        }
    }

    if (isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
}