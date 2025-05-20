//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define MAX_OUTPUT_SIZE 256

// Function to clean the input by removing unsafe characters
void sanitizeInput(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0' && j < MAX_OUTPUT_SIZE - 1; i++) {
        if (isalnum(input[i]) || isspace(input[i]) || input[i] == '-' || input[i] == '_') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

// Function to validate the sanitized input against a given pattern (example: email)
int validateEmail(const char *email) {
    // Check for presence of '@' and '.'
    const char *atSign = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return atSign != NULL && dot != NULL && atSign < dot && atSign != email && dot != email + strlen(email) - 1;
}

// Function to handle user input and sanitize it
void getUserInput() {
    char input[MAX_INPUT_SIZE];
    char sanitizedOutput[MAX_OUTPUT_SIZE];

    printf("Enter your input (up to %d characters, safe characters include letters, digits, spaces, '-', '_'): ", MAX_INPUT_SIZE - 1);
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character from fgets
    input[strcspn(input, "\n")] = 0;

    // Sanitize user input
    sanitizeInput(input, sanitizedOutput);

    // Output sanitized input
    printf("Sanitized Input: %s\n", sanitizedOutput);

    // Example validation for an email
    if (validateEmail(sanitizedOutput)) {
        printf("Valid email detected!\n");
    } else {
        printf("Invalid email format.\n");
    }
}

// Function to display the menu
void displayMenu() {
    printf("User Input Sanitizer Program\n");
    printf("==============================\n");
    printf("1. Enter Input\n");
    printf("2. Exit\n");
}

// Main function to control program flow
int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after integer input

        switch (choice) {
            case 1:
                getUserInput();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);

    return 0;
}