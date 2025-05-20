//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
    // Check if the input is NULL
    if (input == NULL) {
        return NULL;
    }

    // Allocate memory for the sanitized input
    char *sanitized_input = malloc(strlen(input) + 1);
    if (sanitized_input == NULL) {
        return NULL;
    }

    // Copy the input to the sanitized input
    strcpy(sanitized_input, input);

    // Replace any special characters with their HTML equivalents
    for (int i = 0; i < strlen(sanitized_input); i++) {
        switch (sanitized_input[i]) {
            case '&':
                sanitized_input[i] = '&amp;';
                break;
            case '<':
                sanitized_input[i] = '&lt;';
                break;
            case '>':
                sanitized_input[i] = '&gt;';
                break;
            case '"':
                sanitized_input[i] = '&quot;';
                break;
            case '\'':
                sanitized_input[i] = '&apos;';
                break;
        }
    }

    // Return the sanitized input
    return sanitized_input;
}

// Function to test the sanitize_input function
int main() {
    // Get the user input
    char *input = malloc(1024);
    printf("Enter your input: ");
    scanf("%s", input);

    // Sanitize the user input
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the allocated memory
    free(input);
    free(sanitized_input);

    return 0;
}