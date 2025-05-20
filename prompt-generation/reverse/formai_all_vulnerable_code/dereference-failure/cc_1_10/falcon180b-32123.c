//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

// Function to sanitize user input
char* sanitize_input(char* input) {
    char* sanitized_input = malloc(MAX_INPUT_SIZE * sizeof(char));
    int sanitized_input_length = 0;

    // Remove leading/trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized_input[sanitized_input_length++] = input[i];
        }
    }
    sanitized_input[sanitized_input_length] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char* sanitized_input;

    // Get user input
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize input
    sanitized_input = sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free memory
    free(sanitized_input);

    return 0;
}