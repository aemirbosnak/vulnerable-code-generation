//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum length of the string to be checked
#define MAX_STR_LEN 100

// Function to check if a string is a palindrome
bool is_palindrome(const char *str) {
    int len = strlen(str);

    // Check if the string is empty or has only one character
    if (len == 0 || len == 1) {
        return true;
    }

    // Iterate over the string from both sides
    int i = 0;
    int j = len - 1;
    while (i < j) {
        // Compare the characters at positions i and j
        if (str[i] != str[j]) {
            return false;
        }

        // Move the indices towards the center of the string
        i++;
        j--;
    }

    // If all characters match, the string is a palindrome
    return true;
}

int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
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