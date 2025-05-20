//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

bool isPalindrome(char*);

int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    int len = strlen(str);

    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    for (int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }

    if (isPalindrome(str))
    {
        printf("\n%s is a palindrome.\n", str);
    }
    else
    {
        printf("\n%s is not a palindrome.\n", str);
    }

    return 0;
}

bool isPalindrome(char* str)
{
    int len = strlen(str);
    int i = 0;
    int j = len - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }

        i++;
        j--;
    }

    return true;
}