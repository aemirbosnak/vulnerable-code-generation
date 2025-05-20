//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define SANITIZED_LENGTH 256

// Function to sanitize input by removing unwanted characters
void sanitize_input(const char *input, char * sanitized) {
    int j = 0;
    for (int i = 0; input[i] != '\0' && j < SANITIZED_LENGTH - 1; i++) {
        // Allow only alphanumeric characters and basic punctuation
        if (isalnum(input[i]) || isspace(input[i]) || ispunct(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

// Function to display a menu and get user choice
int display_menu() {
    int choice;
    printf("Select an option:\n");
    printf("1. Input Your Name\n");
    printf("2. Input Your Email\n");
    printf("3. Input Your Comment\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("Invalid input. Please enter a number between 1 and 4: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    while (getchar() != '\n'); // Clear the newline character
    return choice;
}

// Function to prompt for input and sanitize it
void get_input(const char *type) {
    char input[MAX_INPUT_LENGTH];
    char sanitized[SANITIZED_LENGTH];

    printf("Please enter your %s: ", type);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        sanitize_input(input, sanitized);
        printf("Sanitized %s: %s\n", type, sanitized);
    } else {
        printf("Error reading input.\n");
    }
}

// Main function of the program
int main() {
    int choice;
    
    printf("Welcome to the User Input Sanitizer Program!\n");

    do {
        choice = display_menu();
        switch (choice) {
            case 1:
                get_input("Name");
                break;
            case 2:
                get_input("Email");
                break;
            case 3:
                get_input("Comment");
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}