//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    // Get the length of the string
    size_t len = strlen(str);

    // Iterate over the string from both ends, comparing characters
    for (size_t i = 0, j = len - 1; i < len / 2; i++, j--) {
        // Ignore case and non-alphabetic characters
        char char1 = tolower(str[i]);
        char char2 = tolower(str[j]);
        if (!isalpha(char1) || !isalpha(char2)) {
            continue;
        }

        // Return false if characters do not match
        if (char1 != char2) {
            return false;
        }
    }

    // If loop completes without returning false, the string is a palindrome
    return true;
}

int main() {
    // Declare variables
    char str[100];
    bool result;

    // Get input from user
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", str);

    // Check if the string is a palindrome and store the result
    result = isPalindrome(str);

    // Print the result
    if (result) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}