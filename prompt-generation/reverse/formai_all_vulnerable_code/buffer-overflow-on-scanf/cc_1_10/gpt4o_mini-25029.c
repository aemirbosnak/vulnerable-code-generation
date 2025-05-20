//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to convert a character to lowercase
char toLowerCase(char c) {
    return tolower(c);
}

// Function to clean the input string by removing non-alphanumeric characters
void cleanString(const char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            cleaned[j++] = toLowerCase(input[i]);
        }
    }
    cleaned[j] = '\0'; // Null-terminate the cleaned string
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

// Main function
int main() {
    char input[MAX_LENGTH];
    char cleaned[MAX_LENGTH];

    printf("Welcome to the C Palindrome Checker!\n");
    printf("Please enter a string to check if it's a palindrome:\n");

    // Read the input string
    fgets(input, MAX_LENGTH, stdin);
    
    // Clear new line character if present
    input[strcspn(input, "\n")] = 0;

    // Clean the input string
    cleanString(input, cleaned);

    // Display the cleaned version
    printf("Cleaned string for palindrome check: \"%s\"\n", cleaned);

    // Check for palindrome
    if (isPalindrome(cleaned)) {
        printf("The input string is a palindrome!\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Additional fun: Check a second time if the user wants
    char repeat;
    do {
        printf("Do you want to check another string? (Y/n): ");
        scanf(" %c", &repeat);
        getchar(); // To consume the newline character

        if (tolower(repeat) == 'y') {
            printf("Please enter the new string to check:\n");
            fgets(input, MAX_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character

            // Clean the new input string
            cleanString(input, cleaned);
            printf("Cleaned string for palindrome check: \"%s\"\n", cleaned);

            // Check for the palindrome again
            if (isPalindrome(cleaned)) {
                printf("The input string is a palindrome!\n");
            } else {
                printf("The input string is not a palindrome.\n");
            }
        }
    } while (tolower(repeat) == 'y');

    printf("Thank you for using the C Palindrome Checker! Have a great day!\n");
    
    return 0;
}