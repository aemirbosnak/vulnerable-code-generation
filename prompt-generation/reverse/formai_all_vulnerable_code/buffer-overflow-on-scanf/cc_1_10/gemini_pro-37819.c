//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(strlen(input) + 1);

    // Copy the first character to the sanitized input
    sanitized_input[0] = input[0];

    // Iterate over the remaining characters in the input
    for (int i = 1; i < strlen(input); i++) {
        // If the character is alphanumeric, copy it to the sanitized input
        if (is_alphanumeric(input[i])) {
            sanitized_input[i] = input[i];
        }
        // Otherwise, replace the character with a space
        else {
            sanitized_input[i] = ' ';
        }
    }

    // Add a null terminator to the sanitized input
    sanitized_input[strlen(input)] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

int main() {
    // Get user input
    char input[100];
    printf("Enter your input: ");
    scanf("%s", input);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the allocated memory
    free(sanitized_input);

    return 0;
}