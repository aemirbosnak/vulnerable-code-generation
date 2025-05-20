//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define SANITIZE_OPTION 1
#define VALIDATE_OPTION 2
#define REMOVE_WHITESPACE_OPTION 3

void print_menu() {
    printf("User Input Sanitizer Menu:\n");
    printf("1. Sanitize Input\n");
    printf("2. Validate Input\n");
    printf("3. Remove Whitespace\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

void sanitize_input(char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

int validate_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && !isspace(input[i])) {
            return 0; // Invalid input
        }
    }
    return 1; // Valid input
}

void remove_whitespace(char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

void clear_buffer() {
    while (getchar() != '\n'); // Clearing the input buffer
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized[MAX_INPUT_LENGTH];
    char no_whitespace[MAX_INPUT_LENGTH];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        clear_buffer();  // Clear the newline character from the input buffer

        if (choice == 4) {
            printf("Exiting the program...\n");
            break;
        }

        printf("Enter your input: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the newline character from input

        switch (choice) {
            case SANITIZE_OPTION:
                sanitize_input(input, sanitized);
                printf("Sanitized Input: '%s'\n", sanitized);
                break;

            case VALIDATE_OPTION:
                if (validate_input(input)) {
                    printf("Input is valid.\n");
                } else {
                    printf("Input is invalid.\n");
                }
                break;

            case REMOVE_WHITESPACE_OPTION:
                remove_whitespace(input, no_whitespace);
                printf("Input without whitespace: '%s'\n", no_whitespace);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}