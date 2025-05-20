//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void display_title() {
    printf("*********************************\n");
    printf("*       Input Sanitizer        *\n");
    printf("*********************************\n");
}

void sanitize_input(char *input, char *sanitized) {
    int j = 0; // Index for sanitized string
    for (int i = 0; input[i] != '\0' && i < MAX_INPUT_LENGTH; i++) {
        if (isalnum(input[i]) || isspace(input[i])) { // Allow alphanumeric and spaces
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    char sanitized_output[MAX_INPUT_LENGTH];

    display_title();

    printf("Enter a string (max %d characters):\n", MAX_INPUT_LENGTH - 1);
    
    // Taking input from the user
    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1; // Exit with error
    }

    // Removing trailing newline from fgets
    user_input[strcspn(user_input, "\n")] = 0;

    // Sanitize the input
    sanitize_input(user_input, sanitized_output);

    // Display the original and sanitized strings
    printf("Original Input: %s\n", user_input);
    printf("Sanitized Output: %s\n", sanitized_output);

    // Additional features
    printf("\nWould you like to enter another input? (y/n): ");
    char choice;
    scanf(" %c", &choice); // Space before %c to ignore leading whitespace

    while (tolower(choice) == 'y') {
        printf("Enter a string (max %d characters):\n", MAX_INPUT_LENGTH - 1);

        // Clear the input buffer before new entry
        while (getchar() != '\n'); // clear the input buffer

        if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
            printf("Error reading input!\n");
            return 1; // Exit with error
        }

        // Removing trailing newline from fgets
        user_input[strcspn(user_input, "\n")] = 0;

        // Sanitize the input again
        sanitize_input(user_input, sanitized_output);

        // Display the original and sanitized strings
        printf("Original Input: %s\n", user_input);
        printf("Sanitized Output: %s\n", sanitized_output);

        printf("\nWould you like to enter another input? (y/n): ");
        scanf(" %c", &choice); // Space before %c to ignore leading whitespace
    }

    printf("Thank you for using the Input Sanitizer!\n");
    return 0;
}