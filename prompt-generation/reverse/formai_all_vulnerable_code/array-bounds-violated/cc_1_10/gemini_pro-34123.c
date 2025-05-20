//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int main() {
    char input[MAX_INPUT_LENGTH];
    int i;
    bool is_sanitized = false;

    // Prompt the user for input.
    printf("Enter a string to be sanitized: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove leading and trailing whitespace.
    for (i = 0; isspace(input[i]); i++) {
        ;
    }
    for (i = strlen(input) - 1; isspace(input[i]) && i >= 0; i--) {
        ;
    }
    if (i >= 0) {
        input[i + 1] = '\0';
    }

    // Convert all characters to lowercase.
    for (i = 0; input[i] != '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Remove all non-alphanumeric characters.
    for (i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i])) {
            input[i] = '_';
        }
    }

    // Set the is_sanitized flag to true.
    is_sanitized = true;

    // Print the sanitized string.
    if (is_sanitized) {
        printf("Sanitized string: %s\n", input);
    } else {
        printf("Error: Sanitization failed.\n");
    }

    return 0;
}