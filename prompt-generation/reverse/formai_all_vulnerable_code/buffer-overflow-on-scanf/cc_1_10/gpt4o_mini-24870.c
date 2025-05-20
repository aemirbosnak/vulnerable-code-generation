//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input, char *sanitized) {
    int i, j = 0;
    // Remove leading whitespace
    while (isspace((unsigned char)input[j])) {
        j++;
    }

    for (i = j; input[i] != '\0' && i < MAX_INPUT_LENGTH; i++) {
        // Only allow alphanumeric characters and basic punctuation
        if (isalnum((unsigned char)input[i]) || ispunct((unsigned char)input[i])) {
            sanitized[strlen(sanitized)] = input[i];
        }
    }
    sanitized[strlen(sanitized)] = '\0'; // Null-terminate the sanitized string
}

void display_menu() {
    printf("=================================\n");
    printf("        User Input Sanitizer     \n");
    printf("=================================\n");
    printf("1. Enter a string to sanitize\n");
    printf("2. Exit\n");
    printf("=================================\n");
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH] = {0};
    int option;

    while (1) {
        display_menu();
        printf("Please choose an option: ");
        scanf("%d", &option);
        getchar(); // Clear the newline character from the buffer

        switch (option) {
            case 1:
                printf("Enter a string to sanitize: ");
                fgets(user_input, sizeof(user_input), stdin);
                user_input[strcspn(user_input, "\n")] = 0; // Remove the trailing newline

                sanitize_input(user_input, sanitized_input);
                printf("Sanitized input: %s\n", sanitized_input);
                
                memset(sanitized_input, 0, sizeof(sanitized_input)); // Clear the sanitized input for next use
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}