//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) {
    int length = strlen(input);
    int i;
    char *sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int sanitized_length = 0;

    // Remove leading and trailing white spaces
    for (i = 0; i < length; i++) {
        if (!isspace(input[i])) {
            sanitized_input[sanitized_length++] = input[i];
        }
    }
    sanitized_input[sanitized_length] = '\0';

    // Remove consecutive white spaces
    for (i = 0; i < sanitized_length; i++) {
        if (isspace(sanitized_input[i])) {
            memmove(&sanitized_input[i], &sanitized_input[i+1], sanitized_length - i - 1);
            sanitized_length--;
        }
    }

    // Remove special characters
    for (i = 0; i < sanitized_length; i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '_';
        }
    }

    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    return 0;
}