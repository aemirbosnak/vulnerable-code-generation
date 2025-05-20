//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }

        // Compare characters
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }
    return 1; // It's a palindrome
}

int main() {
    char input[256]; // Buffer to hold user input
    char ch; // Variable for user choices
    printf("Welcome to the Amazing Palindrome Checker!\n");
    printf("You can check if a word or phrase is a palindrome! Let's get started!\n");

    do {
        // Prompt the user for input
        printf("Please enter your word or phrase (up to 255 characters): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        // Check for palindrome
        if (isPalindrome(input)) {
            printf("\"%s\" is a wonderful palindrome! 🌟\n", input);
        } else {
            printf("\"%s\" is not a palindrome. Better luck next time! 🚫\n", input);
        }

        // Ask if the user wants to check another string
        printf("Would you like to check another string? (y/n): ");
        scanf(" %c", &ch); // Space before %c to consume any newline
        getchar(); // Consume the newline character left by scanf
    } while (ch == 'y' || ch == 'Y');

    printf("Thank you for using the Amazing Palindrome Checker! Goodbye! 👋\n");
    return 0;
}