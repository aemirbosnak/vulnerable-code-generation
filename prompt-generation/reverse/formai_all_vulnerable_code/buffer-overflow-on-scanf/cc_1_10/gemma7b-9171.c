//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>

#define MAX 100

void palindrome_checker(char *str)
{
    int i, j, length = 0;
    char str_copy[MAX];

    strcpy(str_copy, str);

    // Calculate the length of the string
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    // Reverse the string
    for (i = length - 1; i >= 0; i--)
    {
        for (j = 0; str[j] != '\0'; j++)
        {
            if (str[j] == str[i])
            {
                str[j] = str[i] = ' ';
            }
        }
    }

    // Check if the original string is a palindrome
    if (strcmp(str_copy, str) == 0)
    {
        printf("The original string is a palindrome.\n");
    }
    else
    {
        printf("The original string is not a palindrome.\n");
    }
}

int main()
{
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    palindrome_checker(str);

    return 0;
}