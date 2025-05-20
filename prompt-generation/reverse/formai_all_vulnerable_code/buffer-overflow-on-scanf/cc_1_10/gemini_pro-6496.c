//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the string to be checked.
#define MAX_STRING_LENGTH 100

// Function to check if a string is a palindrome.
int is_palindrome(char *str, int length)
{
    // Check if the string is empty or has only one character.
    if (length == 0 || length == 1)
    {
        return 1;
    }

    // Compare the first and last characters of the string.
    if (str[0] != str[length - 1])
    {
        return 0;
    }

    // Recursively check the remaining characters of the string.
    return is_palindrome(str + 1, length - 2);
}

// Main function to test the palindrome checker.
int main()
{
    // Prompt the user to enter a string.
    printf("Enter a string to check if it is a palindrome: ");
    char str[MAX_STRING_LENGTH];
    scanf("%s", str);

    // Get the length of the string.
    int length = strlen(str);

    // Check if the string is a palindrome.
    int is_palindrome_result = is_palindrome(str, length);

    // Print the result.
    if (is_palindrome_result)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}