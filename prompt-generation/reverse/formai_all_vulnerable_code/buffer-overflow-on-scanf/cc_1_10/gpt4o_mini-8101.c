//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

// Function to sanitize user input by removing non-alphanumeric characters
void sanitizeInput(char *input) {
    char sanitized[MAX_INPUT_SIZE];
    int j = 0;

    for (int i = 0; input[i] != '\0' && i < MAX_INPUT_SIZE; i++) {
        // Check if character is alphanumeric
        if (isalnum((unsigned char)input[i])) {
            sanitized[j++] = input[i];
        }
    }

    // Null terminate the sanitized string
    sanitized[j] = '\0';
    strncpy(input, sanitized, MAX_INPUT_SIZE);
}

// Function to display menu options
void displayMenu() {
    printf("==== User Input Sanitizer ====\n");
    printf("1. Enter a new string\n");
    printf("2. Exit\n");
    printf("==============================\n");
}

// Function to handle user input
void handleUserInput() {
    char input[MAX_INPUT_SIZE];

    printf("Please enter a string (up to 255 characters): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        input[strcspn(input, "\n")] = '\0'; 
        sanitizeInput(input);
        printf("Sanitized Input: %s\n", input);
    } else {
        printf("Error reading input!\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-2): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            // Clear the input buffer to avoid infinite loop
            while (getchar() != '\n'); 
            choice = 0;
        } else {
            switch (choice) {
                case 1:
                    handleUserInput();
                    break;
                case 2:
                    printf("Exiting program. Goodbye!\n");
                    break;
                default:
                    fprintf(stderr, "Invalid choice! Please select 1 or 2.\n");
            }
        }
        // Clear the input buffer for the next option
        while (getchar() != '\n'); 
    } while (choice != 2);

    return 0;
}