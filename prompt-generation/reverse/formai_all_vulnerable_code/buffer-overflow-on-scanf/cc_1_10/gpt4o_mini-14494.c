//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize user input
void sanitize_input(char *input) {
    char sanitized_input[MAX_INPUT_LENGTH] = {0};
    int j = 0;

    for(int i = 0; i < strlen(input); i++) {
        // Allow only alphanumeric characters and spaces
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0'; // Null-terminate the sanitized string
    strcpy(input, sanitized_input);
}

// Function to display a menu
void display_menu() {
    printf("---------- Menu ----------\n");
    printf("1. Enter your name\n");
    printf("2. Enter your email\n");
    printf("3. Enter your address\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
}

// Function to get user input safely
void get_user_input(const char *prompt, char *input) {
    printf("%s", prompt);
    if (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        sanitize_input(input);
    }
}

int main() {
    char name[MAX_INPUT_LENGTH];
    char email[MAX_INPUT_LENGTH];
    char address[MAX_INPUT_LENGTH];
    int choice = 0;

    while (1) {
        display_menu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character from the input buffer

        switch (choice) {
            case 1:
                get_user_input("Enter your name: ", name);
                printf("Sanitized name: %s\n", name);
                break;
            case 2:
                get_user_input("Enter your email: ", email);
                printf("Sanitized email: %s\n", email);
                break;
            case 3:
                get_user_input("Enter your address: ", address);
                printf("Sanitized address: %s\n", address);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0); // Exit program safely
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}