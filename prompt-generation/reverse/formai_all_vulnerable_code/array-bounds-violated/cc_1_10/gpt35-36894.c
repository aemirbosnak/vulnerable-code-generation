//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str, int len);

int main()
{
    char str[101], check[101];
    int len_str, len_check;

    printf("Palindrome Checker\n");
    printf("Enter a string to check if it is a palindrome: ");
    fgets(str, 101, stdin);
    len_str = strlen(str);

    // Removing newline character from fgets
    if (str[len_str - 1] == '\n')
    {
        str[len_str - 1] = '\0';
        len_str--;
    }

    // Convert to lowercase and remove non-alpha characters
    int i, j = 0;
    for (i = 0; i < len_str; i++)
    {
        if (isalpha(str[i]))
        {
            check[j++] = tolower(str[i]);
        }
    }
    check[j] = '\0';
    len_check = j;

    if (isPalindrome(check, len_check))
    {
        printf("'%s' is a palindrome!\n", str);
    }
    else
    {
        printf("'%s' is not a palindrome.\n", str);
    }

    return 0;
}

// Returns 1 if str is a palindrome, 0 otherwise
int isPalindrome(char *str, int len)
{
    int i, j;
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}