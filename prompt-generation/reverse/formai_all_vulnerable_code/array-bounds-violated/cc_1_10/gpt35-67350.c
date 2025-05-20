//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[50], rev[50];
    int len = 0, flag = 0, i = 0, j = 0;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    len = strlen(str);

    // Remove newline character if present
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    // Copy the string to a new variable in lowercase
    char tmp[len];
    for (i = 0; i < len; i++)
    {
        tmp[i] = tolower(str[i]);
    }
    tmp[i] = '\0';

    // Reverse the string
    for (i = len - 1; i >= 0; i--)
    {
        if (isalpha(tmp[i]) || isdigit(tmp[i]))
        {
            rev[j++] = tmp[i];
        }
    }
    rev[j] = '\0';

    // Check palindrome
    for (i = 0; i < j; i++)
    {
        if (tmp[i] != rev[i])
        {
            flag = 1;
            break;
        }
    }

    // Print result
    if (flag)
    {
        printf("The string is not a palindrome.\n");
    }
    else
    {
        printf("The string is a palindrome!\n");
    }

    return 0;
}