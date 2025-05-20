//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define MAX_SANITIZED_SIZE 256

// Function to sanitize user input
void sanitize_input(const char *input, char *sanitized) {
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is alphanumeric or a space
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

// Function to display a magical menu
void display_menu() {
    printf("=================================\n");
    printf("   Welcome to the Input Sanitize  \n");
    printf("          Enchanted Forest!      \n");
    printf("=================================\n");
    printf("Please enter the mystical phrase: \n");
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    char sanitized_input[MAX_SANITIZED_SIZE];

    // Display the enchanting menu
    display_menu();

    // Read the user input from the enchanted scroll
    printf("Your input: ");
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove the newline character if present
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    // Sanitize the user input
    sanitize_input(user_input, sanitized_input);

    // Display the result of the input sanitization
    printf("\n=================================\n");
    printf("        The Cleaned Input       \n");
    printf("=================================\n");
    printf("Your sanitized phrase: \"%s\"\n", sanitized_input);
    
    // Offer further actions in the enchanted forest
    printf("\nWhat would you like to do next?\n");
    printf("1. Enter another phrase\n");
    printf("2. Exit the enchanted forest\n");
    printf("Choose: ");
    
    int choice;
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid input for choice.\n");
        return 1;
    }

    // Handle user choice
    if (choice == 1) {
        printf("Alas! This enchanted forest allows only one phrase at a time. Returning to the entrance...\n");
    } else if (choice == 2) {
        printf("Thank you for visiting the Input Sanitize Enchanted Forest. Have a magical day!\n");
    } else {
        printf("Beware! You've entered an unknown realm, where choices lead to unexpected adventures.\n");
    }

    printf("=================================\n");
    return 0;
}