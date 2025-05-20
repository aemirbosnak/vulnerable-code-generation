//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize user input
void sanitize_input(char *input) {
    char *src = input, *dst = input;
    
    // Remove leading whitespace
    while (isspace((unsigned char)*src)) src++;
    
    // Process each character
    while (*src) {
        // Skip control characters
        if (isprint((unsigned char)*src) && !isspace((unsigned char)*src)) {
            *dst++ = *src; // Copy printable and non-space characters
        }
        src++;
    }
    
    // Null terminate the sanitized string
    *dst = '\0';
    
    // Optionally limit the length
    if (dst - input > MAX_INPUT_LENGTH - 1) {
        input[MAX_INPUT_LENGTH - 1] = '\0'; // Truncate if too long
    }
}

// Function to display menu and get choice
int display_menu() {
    int choice;
    printf("Select an option:\n");
    printf("1. Enter a string\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
        printf("Invalid choice. Please enter 1 or 2: ");
        while(getchar() != '\n'); // clear input buffer
    }
    return choice;
}

// Function to get user input
void get_user_input(char *input) {
    printf("Enter a string: ");
    getchar(); // clear the new line left in the buffer
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        int choice = display_menu();

        if (choice == 1) {
            get_user_input(input);
            sanitize_input(input);
            printf("Sanitized output: '%s'\n", input);
        } else {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }

    return 0;
}