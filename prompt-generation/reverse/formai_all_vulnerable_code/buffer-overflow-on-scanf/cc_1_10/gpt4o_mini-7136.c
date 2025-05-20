//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a given string is a palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Move left index to the next valid character
        while (left < right && !isalnum((unsigned char)str[left])) {
            left++;
        }
        // Move right index to the previous valid character
        while (left < right && !isalnum((unsigned char)str[right])) {
            right--;
        }

        // Compare characters, ignoring case
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }
    return 1; // It's a palindrome!
}

// Main function to drive the program
int main() {
    char input[100]; // Declare a string to hold user input
    char choice;     // To store user choice for another input

    printf("🚀 Welcome to the Palindrome Checker! 🌟\n");
    printf("Let's see if your string is a palindrome, shall we? 🤔\n");

    do {
        // Prompt the user for input
        printf("Please enter a string (up to 99 characters): ");
        fgets(input, sizeof(input), stdin); // Safely read a line of input

        // Remove the newline character if present
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is a palindrome
        if (isPalindrome(input)) {
            printf("🎉 Awesome! The string \"%s\" is a palindrome! 🎉\n", input);
        } else {
            printf("😢 Oops! The string \"%s\" is not a palindrome. 😢\n", input);
        }

        // Prompt the user to check another string
        printf("Would you like to check another string? (y/n): ");
        scanf(" %c", &choice); // Read user choice
        getchar(); // Consume the newline character from buffer

    } while (choice == 'y' || choice == 'Y'); // Loop if user wants to continue

    printf("🚀 Thanks for checking and have a palindrome-filled day! 🌟\n");
    return 0; // Exit the program
}