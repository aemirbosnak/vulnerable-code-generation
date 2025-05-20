//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    // Declare variables
    int len = strlen(str);
    int i;

    // Check if the string is empty or has only one character
    if (len <= 1)
    {
        return 1;
    }

    // Iterate over the string and compare characters
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }

    // Return 1 if the string is a palindrome, 0 otherwise
    return 1;
}

// Function to test the palindrome checker
int main()
{
    // Declare variables
    char str[100];
    int result;

    // Get the string from the user
    printf("Enter a string: ");
    gets(str);

    // Check if the string is a palindrome
    result = isPalindrome(str);

    // Print the result
    if (result)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    // Return 0 to indicate successful execution
    return 0;
}