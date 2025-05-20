//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitize_input(char* input) {
    int i = 0;
    char sanitized_input[MAX_INPUT_LENGTH];

    // Remove leading and trailing whitespaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Copy sanitized input to new string
    strncpy(sanitized_input, input, MAX_INPUT_LENGTH - 1);
    sanitized_input[MAX_INPUT_LENGTH - 1] = '\0';

    // Replace special characters with underscores
    for (i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '_';
        }
    }

    // Copy sanitized input back to original string
    strncpy(input, sanitized_input, MAX_INPUT_LENGTH - 1);
    input[MAX_INPUT_LENGTH - 1] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter some text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}