//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int is_palindrome(const char* str)
{
    // Get the length of the string
    int len = strlen(str);

    // Initialize the left and right pointers
    int left = 0;
    int right = len - 1;

    // Compare the characters from the left and right pointers
    while (left < right)
    {
        // If the characters are not the same, the string is not a palindrome
        if (tolower(str[left]) != tolower(str[right]))
        {
            return 0;
        }

        // Move the left and right pointers towards each other
        left++;
        right--;
    }

    // If the left and right pointers have crossed each other, the string is a palindrome
    return 1;
}

int main()
{
    // Get the input string from the user
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