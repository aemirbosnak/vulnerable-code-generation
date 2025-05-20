//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitize_input(const char* input, char* output, size_t output_size) {
    size_t output_index = 0;
    for(size_t i = 0; i < strlen(input) && output_index < output_size - 1; ++i) {
        // Keep only alphabets, numbers, and basic punctuation
        if (isalnum(input[i]) || isspace(input[i]) || ispunct(input[i])) {
            output[output_index++] = input[i];
        }
    }
    output[output_index] = '\0'; // Null terminate the sanitized string
}

// Function to display the menu
void display_menu() {
    printf("\n=== User Input Sanitizer ===\n");
    printf("1. Enter Input\n");
    printf("2. Exit\n");
    printf("==============================\n");
}

// Main driver function
int main() {
    char input[256];
    char sanitized[256];
    int choice;

    do {
        display_menu();
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter a string to sanitize: ");
                fgets(input, sizeof(input), stdin);
                
                // Remove new line character if present
                input[strcspn(input, "\n")] = 0;

                // Sanitize the user input
                sanitize_input(input, sanitized, sizeof(sanitized));

                // Display sanitized output
                printf("Sanitized output: \"%s\"\n", sanitized);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}