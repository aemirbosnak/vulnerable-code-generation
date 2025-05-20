//GEMINI-pro DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a palindrome
int is_palindrome(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Iterate over the string from both ends and compare characters
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

// Function to find the longest palindromic substring
char *longest_palindrome(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Initialize variables to store the start and end indices of the longest palindromic substring
    int start = 0, end = 0;
    int max_length = 1;

    // Iterate over the string
    for (int i = 0; i < len; i++) {
        // Check for odd-length palindromes centered at i
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < len && str[left] == str[right]) {
            if (right - left + 1 > max_length) {
                start = left;
                end = right;
                max_length = right - left + 1;
            }
            left--;
            right++;
        }

        // Check for even-length palindromes centered at i and i+1
        left = i, right = i + 1;
        while (left >= 0 && right < len && str[left] == str[right]) {
            if (right - left + 1 > max_length) {
                start = left;
                end = right;
                max_length = right - left + 1;
            }
            left--;
            right++;
        }
    }

    // Allocate memory for the longest palindromic substring
    char *longest = malloc(max_length + 1);
    strncpy(longest, str + start, max_length);
    longest[max_length] = '\0';

    return longest;
}

int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    // Find the longest palindromic substring
    char *longest = longest_palindrome(str);
    printf("The longest palindromic substring of '%s' is '%s'.\n", str, longest);

    // Free the allocated memory
    free(longest);

    return 0;
}