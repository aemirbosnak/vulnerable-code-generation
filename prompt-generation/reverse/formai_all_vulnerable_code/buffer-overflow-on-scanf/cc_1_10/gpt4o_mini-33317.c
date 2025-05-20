//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

// Function to convert a string to lower case and remove non-alphanumeric characters
void preprocessString(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

// Function to display menu
void displayMenu() {
    printf("\n--- Palindrome Checker ---\n");
    printf("1. Check another string\n");
    printf("2. Exit\n");
    printf("-------------------------\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    char input[MAX_LENGTH];
    char processed[MAX_LENGTH];
    int choice = 1;

    printf("Welcome to the Palindrome Checker!\n");

    while (choice == 1) {
        printf("\nEnter a string to check: ");
        fgets(input, MAX_LENGTH, stdin);
        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Preprocess the string
        preprocessString(input, processed);

        // Check if the processed string is a palindrome
        if (isPalindrome(processed)) {
            printf("The string \"%s\" is a palindrome.\n", input);
        } else {
            printf("The string \"%s\" is not a palindrome.\n", input);
        }

        // Display menu and get user choice
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        if (choice < 1 || choice > 2) {
            printf("Invalid option. Please try again.\n");
            choice = 1; // Reset choice to continue the loop
        }
    }

    printf("Thank you for using the Palindrome Checker. Goodbye!\n");
    return 0;
}