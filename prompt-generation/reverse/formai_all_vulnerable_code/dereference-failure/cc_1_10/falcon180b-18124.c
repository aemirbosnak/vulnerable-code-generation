//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

/**
 * Function to sanitize user input by removing any non-alphanumeric characters
 * and trimming whitespace around the input.
 *
 * @param input The input string to sanitize.
 * @return The sanitized input string.
 */
char* sanitize_input(char* input) {
    int i, j;
    char* sanitized_input = malloc(MAX_INPUT_SIZE);

    // Remove non-alphanumeric characters
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';

    // Trim whitespace around the input
    char* start = sanitized_input;
    char* end = sanitized_input + strlen(sanitized_input) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end)) {
        end--;
    }
    memmove(sanitized_input, start, end - start + 1);
    sanitized_input[end - start + 1] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter some text to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);
    return 0;
}