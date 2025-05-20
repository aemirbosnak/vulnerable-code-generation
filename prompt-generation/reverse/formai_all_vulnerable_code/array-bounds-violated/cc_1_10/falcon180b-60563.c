//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maximum length of input string

int isPalindrome(char *str); // Function to check if a string is a palindrome

int main() {
    char input[MAX_LENGTH]; // Input string
    int length; // Length of input string
    int isPal; // Flag to indicate if input string is a palindrome

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    length = strlen(input) - 1;
    input[length] = '\0';

    // Convert input string to lowercase
    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }

    // Check if input string is a palindrome
    isPal = isPalindrome(input);

    // Print result
    if (isPal) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    int i;

    // Compare characters from both ends of the string
    for (i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}