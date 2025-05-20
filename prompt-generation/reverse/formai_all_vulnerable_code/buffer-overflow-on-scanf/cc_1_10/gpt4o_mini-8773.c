//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define SANITIZED_OUTPUT_SIZE 512

// Function to sanitize user input
void sanitizeInput(const char *input, char *sanitizedOutput) {
    int j = 0;
    // Clean the input - Allow only alphanumeric and some selected characters
    for (int i = 0; input[i] != '\0' && j < SANITIZED_OUTPUT_SIZE - 1; i++) {
        char ch = input[i];
        if (isalnum(ch) || ch == ' ' || ch == '-' || ch == '.') {
            sanitizedOutput[j++] = ch;
        }
    }
    sanitizedOutput[j] = '\0'; // Null-terminate the sanitized string
}

// Function to display a menu
void displayMenu() {
    printf("Welcome to the User Input Sanitizer Program!\n");
    printf("1. Enter your input\n");
    printf("2. Exit\n");
}

// Function to handle user input
void handleUserInput() {
    char userInput[MAX_INPUT_SIZE];
    char sanitizedOutput[SANITIZED_OUTPUT_SIZE];

    printf("Please enter a string (up to %d characters): ", MAX_INPUT_SIZE - 1);
    if (fgets(userInput, MAX_INPUT_SIZE, stdin) != NULL) {
        // Remove the newline character if it exists
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
        }

        // Sanitize input
        sanitizeInput(userInput, sanitizedOutput);
        printf("Sanitized Output: %s\n", sanitizedOutput);
    } else {
        printf("Error reading input!\n");
    }
}

int main() {
    int choice = 0;

    do {
        displayMenu();
        printf("Please select an option: ");
        if (scanf("%d", &choice) != 1) {
            // Clear the invalid input
            while (getchar() != '\n');
            choice = 0;
            printf("Invalid input! Please enter a number.\n");
        } else {
            // Flush the newline character left in the buffer
            while (getchar() != '\n');

            switch (choice) {
                case 1:
                    handleUserInput();
                    break;
                case 2:
                    printf("Exiting program. Thank you!\n");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        }
    } while (choice != 2);

    return 0;
}