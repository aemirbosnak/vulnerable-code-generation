//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str)
{
    // Get the length of the string
    int len = strlen(str);

    // Check if the string is empty or has only one character
    if (len == 0 || len == 1)
    {
        return 1;
    }

    // Initialize left and right pointers
    int left = 0;
    int right = len - 1;

    // Compare characters from left and right pointers
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }

        // Move left and right pointers towards the center
        left++;
        right--;
    }

    // If all characters match, return 1
    return 1;
}

// Main function
int main()
{
    // Get the input string
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    int is_palindrome_result = is_palindrome(str);

    // Print the result
    if (is_palindrome_result)
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}