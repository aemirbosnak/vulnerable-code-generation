//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to clean the input string
void clean_string(char *str, char *cleaned) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is alphanumeric
        if (isalnum(str[i])) {
            cleaned[j++] = tolower(str[i]); // Convert to lowercase
        }
    }
    cleaned[j] = '\0'; // Null-terminate cleaned string
}

// Function to check if the string is a palindrome
bool is_palindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    char input[256];
    char cleaned[256];

    printf("🌟 Welcome to the Fantastic Palindrome Checker! 🌟\n");
    printf("✨ Enter a string to see if it's a palindrome: \n");
    
    // Get user input
    fgets(input, sizeof(input), stdin);
    // Clean the input string
    clean_string(input, cleaned);

    // Check for palindromes
    if (is_palindrome(cleaned)) {
        printf("🎉 Hooray! \"%s\" is a palindrome! 🎉\n", input);
    } else {
        printf("🚫 Oops! \"%s\" is NOT a palindrome. 🚫\n", input);
    }

    // Let's add some extra fun by continuing to check more strings
    char choice;
    printf("Would you like to check another string? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("✨ Enter another string: \n");
        getchar(); // Clear the newline from the buffer
        fgets(input, sizeof(input), stdin);
        clean_string(input, cleaned);
        
        if (is_palindrome(cleaned)) {
            printf("🎉 Hooray! \"%s\" is a palindrome! 🎉\n", input);
        } else {
            printf("🚫 Oops! \"%s\" is NOT a palindrome. 🚫\n", input);
        }

        printf("Would you like to check another string? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("🥳 Thank you for using the Palindrome Checker! Have a splendid day! 🌈\n");
    return 0;
}