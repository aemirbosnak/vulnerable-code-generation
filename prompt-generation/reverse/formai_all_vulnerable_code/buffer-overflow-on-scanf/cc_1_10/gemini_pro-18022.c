//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1024

// Declare a function to check if a string is a palindrome
int is_palindrome(char *str);

int main() {
    // Declare a variable to store the user input
    char input[MAX_STRING_SIZE];

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Get the user input
    scanf("%s", input);

    // Check if the string is a palindrome
    int is_palindrome_result = is_palindrome(input);

    // Print the result
    if (is_palindrome_result) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

// Define the function to check if a string is a palindrome
int is_palindrome(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Declare two variables to store the indices of the characters being compared
    int i = 0;
    int j = len - 1;

    // Compare the characters from the beginning and end of the string
    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // The string is not a palindrome
        }

        // Increment the indices
        i++;
        j--;
    }

    // The string is a palindrome
    return 1;
}