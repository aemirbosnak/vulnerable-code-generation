//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to determine if a given string is a palindrome
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Ignore non-alphanumeric characters and convert to lowercase
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
    
    return 1; // It's a palindrome!
}

// Function to take user input and check for palindrome
void checkPalindrome() {
    char input[256]; // Create a buffer for input

    printf("🎉 Welcome to the Palindrome Checker! 🎉\n");
    printf("Enter a string (up to 255 characters): ");
    
    // Read user input
    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline character from input
    input[strcspn(input, "\n")] = 0;

    // Call the isPalindrome function and display the result
    if (isPalindrome(input)) {
        printf("🌟 Great news! '%s' is a palindrome! 🌟\n", input);
    } else {
        printf("😢 Oops! '%s' is not a palindrome. 😢\n", input);
    }
}

// Main function to drive the program
int main() {
    char continueProgram = 'y'; // Control variable for loop
    
    while (continueProgram == 'y' || continueProgram == 'Y') {
        checkPalindrome();
        printf("Do you want to check another string? (y/n): ");
        scanf(" %c", &continueProgram); // Ask user to continue or not
        getchar(); // Clear the newline character from the buffer
    }

    // Farewell message
    printf("👋 Thank you for using the Palindrome Checker! 👋\n");
    return 0;
}