//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(strlen(input) + 1);

    // Initialize the sanitized input
    strcpy(sanitized_input, "");

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current character is a valid character
        if (input[i] >= 'a' && input[i] <= 'z') {
            // Add the current character to the sanitized input
            strncat(sanitized_input, &input[i], 1);
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            // Add the current character to the sanitized input
            strncat(sanitized_input, &input[i], 1);
        } else if (input[i] >= '0' && input[i] <= '9') {
            // Add the current character to the sanitized input
            strncat(sanitized_input, &input[i], 1);
        } else if (input[i] == ' ') {
            // Add the current character to the sanitized input
            strncat(sanitized_input, &input[i], 1);
        } else if (input[i] == '.' || input[i] == ',' || input[i] == '?' || input[i] == '!') {
            // Add the current character to the sanitized input
            strncat(sanitized_input, &input[i], 1);
        }
    }

    // Return the sanitized input
    return sanitized_input;
}

// Main function
int main() {
    // Get the user input
    char input[100];
    printf("Enter your input: ");
    gets(input);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    return 0;
}