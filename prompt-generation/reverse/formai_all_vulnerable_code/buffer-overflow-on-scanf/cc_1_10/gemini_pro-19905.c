//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: shocked
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

/**
 * Checks if the given string is a palindrome.
 *
 * Args:
 *     str: The string to check.
 *
 * Returns:
 *     True if the string is a palindrome, othewise False.
 */
bool is_palindrome(const char *str)
{
    int len = strlen(str);

    if (len == 0)
    {
        return true;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }

    return true;
}

/**
 * Reads a string from the standard input and checks if it is a palindrome.
 *
 * Prints "The string is a palindrome :)" if the string is a palindrome, otherwise prints "The string is not a palindrome :(".
 */
void main()
{
    char str[MAX_STR_LEN];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_palindrome(str))
    {
        printf("The string is a palindrome :)\n");
    }
    else
    {
        printf("The string is not a palindrome :(\n");
    }
}