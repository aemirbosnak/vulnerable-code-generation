//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Initialize the left and right pointers
    int left = 0, right = len - 1;

    // Compare characters from left and right
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;  // Not a palindrome
        }
        left++;
        right--;
    }

    return 1;  // Palindrome
}

// Function to dynamically allocate memory for a string
char *allocateString(int size) {
    // Allocate memory for the string
    char *str = (char *)malloc(size * sizeof(char));

    // Check if memory was allocated successfully
    if (str == NULL) {
        printf("Error allocating memory for string!\n");
        exit(1);  // Exit the program with an error code
    }

    return str;
}

// Main function
int main() {
    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Get the user's input
    char *str = allocateString(100);  // Allocate memory for a string of maximum 100 characters
    scanf("%s", str);

    // Check if the string is a palindrome
    int result = isPalindrome(str);

    // Print the result
    if (result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Free the memory allocated for the string
    free(str);

    return 0;
}