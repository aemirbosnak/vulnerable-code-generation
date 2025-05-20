//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void sanitize_input(char *input) {
    char *sanitized_input = malloc(MAX_INPUT_SIZE);
    int length = strlen(input);

    // Remove leading and trailing whitespace
    int start_index = 0;
    int end_index = length - 1;
    while (start_index < length && isspace(input[start_index])) {
        start_index++;
    }
    while (end_index >= 0 && isspace(input[end_index])) {
        end_index--;
    }
    length = end_index - start_index + 1;

    // Copy sanitized input to new buffer
    strncpy(sanitized_input, input + start_index, length);
    sanitized_input[length] = '\0';

    // Replace non-alphanumeric characters with underscores
    char *ptr = sanitized_input;
    while (*ptr) {
        if (!isalnum(*ptr)) {
            *ptr = '_';
        }
        ptr++;
    }

    // Copy sanitized input back to original buffer
    strcpy(input, sanitized_input);
    free(sanitized_input);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter some text to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}