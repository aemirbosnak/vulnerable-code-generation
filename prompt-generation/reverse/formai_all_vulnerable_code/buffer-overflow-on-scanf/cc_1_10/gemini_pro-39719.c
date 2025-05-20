//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STR_LEN 100

// Function to reverse a string
void reverse_str(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int max_len = 0;
    int start = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int sub_len = j - i + 1;
            if (sub_len > max_len && is_palindrome(str + i)) {
                max_len = sub_len;
                start = i;
            }
        }
    }
    return strndup(str + start, max_len);
}

// Main function
int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    scanf("%s", str);

    // Print the original string
    printf("Original string: %s\n", str);

    // Reverse the string
    reverse_str(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    // Check if the string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Find the longest palindrome in the string
    char *longest_pal = longest_palindrome(str);

    // Print the longest palindrome
    printf("Longest palindrome: %s\n", longest_pal);

    // Free the allocated memory
    free(longest_pal);

    return 0;
}