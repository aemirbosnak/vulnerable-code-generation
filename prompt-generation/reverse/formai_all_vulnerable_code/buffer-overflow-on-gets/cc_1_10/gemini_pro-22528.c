//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to reverse a string
void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// A function to check if a string is a palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

// A utility function to print a string
void printString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }
}

// The main function
int main()
{
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Print the original string
    printf("Original string: ");
    printString(str);

    // Reverse the string
    reverse(str);

    // Print the reversed string
    printf("\nReversed string: ");
    printString(str);

    // Check if the string is a palindrome
    int is_palindrome = isPalindrome(str);

    // Print the result
    if (is_palindrome)
    {
        printf("\nThe string is a palindrome.\n");
    }
    else
    {
        printf("\nThe string is not a palindrome.\n");
    }

    return 0;
}