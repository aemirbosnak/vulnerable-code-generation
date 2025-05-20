//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024

// Function to check if a string is a palindrome
bool is_palindrome(const char *str) {
    // Get the length of the string
    size_t len = strlen(str);

    // Check if the string is empty or has only one character
    if (len == 0 || len == 1) {
        return true;
    }

    // Create a pointer to the beginning of the string
    const char *start = str;

    // Create a pointer to the end of the string
    const char *end = str + len - 1;

    // Iterate over the string, comparing the first and last characters
    while (start < end) {
        // Ignore case when comparing the characters
        if (tolower(*start) != tolower(*end)) {
            return false;
        }

        // Move the pointers closer to the center of the string
        start++;
        end--;
    }

    // If the loop finishes without returning false, the string is a palindrome
    return true;
}

// Main function
int main() {
    // Get the input string from the user
    char str[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    bool is_palindrome_result = is_palindrome(str);

    // Print the result
    if (is_palindrome_result) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}