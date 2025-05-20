//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input, char *sanitized) {
    int j = 0;
    for (int i = 0; input[i] != '\0' && i < MAX_INPUT_LENGTH; i++) {
        // Allow only alphanumeric characters and basic punctuation
        if (isalnum(input[i]) || isspace(input[i]) || ispunct(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

void display_menu() {
    printf("**********************************\n");
    printf("*          User Input            *\n");
    printf("*         Sanitizer Program      *\n");
    printf("**********************************\n");
    printf("1. Input a string\n");
    printf("2. Exit\n");
    printf("**********************************\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized[MAX_INPUT_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Please select an option: ");
        scanf("%d", &choice);

        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter a string (max %d characters): ", MAX_INPUT_LENGTH - 1);
                fgets(input, sizeof(input), stdin);
                
                // Remove trailing newline character, if present
                size_t len = strlen(input);
                if (len > 0 && input[len - 1] == '\n') {
                    input[len - 1] = '\0';
                }

                sanitize_input(input, sanitized);
                printf("Original Input: %s\n", input);
                printf("Sanitized Output: %s\n", sanitized);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}