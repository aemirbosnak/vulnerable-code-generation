//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input) {
    char sanitized[MAX_INPUT_LENGTH];
    int j = 0;

    for (int i = 0; input[i] != '\0' && j < MAX_INPUT_LENGTH - 1; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized);
}

void get_user_input(char *prompt, char *input) {
    printf("%s", prompt);
    if (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
    }
}

void display_menu() {
    printf("1. Enter a string\n");
    printf("2. Exit\n");
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Exiting...\n");
            return 1;
        }
        
        // Clear stdin buffer to avoid reading extra characters
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                get_user_input("Please enter a string (alphanumeric only): ", user_input);
                sanitize_input(user_input);
                printf("Sanitized input: \"%s\"\n", user_input);
                break;
            case 2:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}