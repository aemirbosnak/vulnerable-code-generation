//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

void sanitizeInput(char *input, char *sanitized) {
    int j = 0;  // Index for sanitized array
    for (int i = 0; input[i] != '\0' && i < MAX_INPUT_SIZE; i++) {
        // Check if the character is a valid alphanumeric character or whitespace
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void displayMenu() {
    printf("=========================================\n");
    printf("             Input Sanitizer           \n");
    printf("=========================================\n");
    printf("1. Enter input to sanitize\n");
    printf("2. Exit\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char sanitized[MAX_INPUT_SIZE];
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-2): ");
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid choice. Please enter a number (1-2).\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter your input (max %d characters): ", MAX_INPUT_SIZE - 1);
                getchar();  // Clear the newline left by previous scanf
                fgets(input, MAX_INPUT_SIZE, stdin);
                
                // Remove newline character from the input
                input[strcspn(input, "\n")] = 0;

                sanitizeInput(input, sanitized);
                
                // Convert sanitized string to uppercase for uniformity
                toUpperCase(sanitized);

                printf("Sanitized Input: %s\n", sanitized);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose 1 or 2.\n");
                break;
        }
    }

    return 0;
}