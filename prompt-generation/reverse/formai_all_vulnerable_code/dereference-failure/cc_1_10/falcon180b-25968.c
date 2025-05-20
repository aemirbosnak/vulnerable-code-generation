//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1000

// Function to sanitize user input
char *sanitize_input(char *input) {
    int i, j;
    char *sanitized_input = malloc(MAX_INPUT_SIZE);
    sanitized_input[0] = '\0';

    // Remove leading and trailing spaces
    while (isspace(input[0])) {
        input++;
    }

    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove any non-alphanumeric characters
    for (i = 0; input[i]!= '\0'; i++) {
        if (!isalnum(input[i])) {
            continue;
        }

        sanitized_input = realloc(sanitized_input, strlen(sanitized_input) + 1);
        sanitized_input[strlen(sanitized_input)] = tolower(input[i]);
    }

    // Check if input is empty after sanitization
    if (sanitized_input[0] == '\0') {
        free(sanitized_input);
        sanitized_input = NULL;
    }

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *sanitized_input;

    printf("Enter some input to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the input
    sanitized_input = sanitize_input(input);

    if (sanitized_input == NULL) {
        printf("Input is empty after sanitization.\n");
    } else {
        printf("Sanitized input: %s\n", sanitized_input);
    }

    free(sanitized_input);
    return 0;
}