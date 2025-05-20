//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char *user_input = malloc(MAX_INPUT_SIZE * sizeof(char));
    if (user_input == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("Enter your input: ");
    fgets(user_input, MAX_INPUT_SIZE, stdin);

    // Remove trailing newline character
    if (user_input[strlen(user_input) - 1] == '\n') {
        user_input[strlen(user_input) - 1] = '\0';
    }

    // Check for invalid characters
    for (int i = 0; i < strlen(user_input); i++) {
        if (!isalnum(user_input[i]) && !isspace(user_input[i])) {
            printf("Invalid character: %c\n", user_input[i]);
            free(user_input);
            return EXIT_FAILURE;
        }
    }

    // Check for excessive whitespace
    if (strlen(user_input) > 0 && isspace(user_input[0])) {
        printf("Excessive whitespace at the beginning of the input\n");
        free(user_input);
        return EXIT_FAILURE;
    }

    // Check for excessive spaces between words
    for (int i = 1; i < strlen(user_input); i++) {
        if (isspace(user_input[i]) && isspace(user_input[i - 1])) {
            printf("Excessive spaces between words\n");
            free(user_input);
            return EXIT_FAILURE;
        }
    }

    // Check for trailing whitespace
    if (strlen(user_input) > 0 && isspace(user_input[strlen(user_input) - 1])) {
        printf("Excessive whitespace at the end of the input\n");
        free(user_input);
        return EXIT_FAILURE;
    }

    // Sanitized input is now stored in the user_input variable
    printf("Sanitized input: %s\n", user_input);

    free(user_input);
    return EXIT_SUCCESS;
}