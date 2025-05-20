//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Preprocessor macros for code clarity
#define TRUE 1
#define FALSE 0
#define PALINDROME TRUE
#define NOT_PALINDROME FALSE
#define MAX_STRING_LENGTH 100

// Function declarations
int isPalindrome(char* string);
void printPalindromeStatus(char* string, int isPalindrome);

// Main function
int main() {
    // Declare variables
    char string[MAX_STRING_LENGTH];
    int isPalindromeStatus;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    scanf("%s", string);

    // Check if the string is a palindrome
    isPalindromeStatus = isPalindrome(string);

    // Print the palindrome status
    printPalindromeStatus(string, isPalindromeStatus);

    return 0;
}

// Function to check if a string is a palindrome
int isPalindrome(char* string) {
    // Declare variables
    int length = strlen(string);
    int i;

    // Check if the string is empty or has only one character
    if (length == 0 || length == 1) {
        return PALINDROME;
    }

    // Check if the first and last characters are the same
    for (i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return NOT_PALINDROME;
        }
    }

    // Return TRUE if the string is a palindrome, otherwise return FALSE
    return PALINDROME;
}

// Function to print the palindrome status
void printPalindromeStatus(char* string, int isPalindrome) {
    // Print the string
    printf("The string '%s' is ", string);

    // Print the palindrome status
    if (isPalindrome == PALINDROME) {
        printf("a palindrome.\n");
    } else {
        printf("not a palindrome.\n");
    }
}