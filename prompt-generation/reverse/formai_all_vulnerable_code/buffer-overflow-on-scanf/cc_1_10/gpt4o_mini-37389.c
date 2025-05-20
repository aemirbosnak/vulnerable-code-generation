//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given string is a palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    // Loop until the left index is less than the right index
    while (left < right) {
        // Move left index to the next valid character
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        // Move right index to the previous valid character
        while (left < right && !isalnum(str[right])) {
            right--;
        }

        // Check if characters are the same (ignoring case)
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }

    return 1; // It is a palindrome
}

// Function to display a friendly message
void greetUser() {
    printf("=========================================\n");
    printf("      Welcome to the Palindrome Checker\n");
    printf("=========================================\n");
    printf("This program will help you determine if \n");
    printf("the given string is a palindrome or not.\n");
    printf("A special thanks to the developers who \n");
    printf("made this possible and to you for using it!\n");
    printf("=========================================\n");
}

// Function to get user input in a safe way
void getInput(char *buffer, size_t size) {
    printf("Please enter a string: ");
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove the newline character at the end if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

// Main function
int main() {
    // Greet the user
    greetUser();

    // Define a buffer to store user input
    char inputBuffer[256];

    // Get user input
    getInput(inputBuffer, sizeof(inputBuffer));

    // Check if the input is a palindrome
    if (isPalindrome(inputBuffer)) {
        printf("The string you entered is a palindrome! 🎉\n");
    } else {
        printf("Oops! The string you entered is not a palindrome. 😢\n");
    }

    // Offer to check another string
    char continueCheck;
    printf("Would you like to check another string? (y/n): ");
    scanf(" %c", &continueCheck);

    // Loop to check multiple strings if the user wants
    while (continueCheck == 'y' || continueCheck == 'Y') {
        getInput(inputBuffer, sizeof(inputBuffer));
        if (isPalindrome(inputBuffer)) {
            printf("The string you entered is a palindrome! 🎉\n");
        } else {
            printf("Oops! The string you entered is not a palindrome. 😢\n");
        }
        printf("Would you like to check another string? (y/n): ");
        scanf(" %c", &continueCheck);
    }

    // Closing message
    printf("Thank you for using the Palindrome Checker! Have a wonderful day! 😊\n");
    return 0;
}