//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 1000
#define WHITESPACE " \t\n\r\f\v"

/* Function to sanitize user input */
void sanitize_input(char *input) {
    int i, j;
    char *whitespace = WHITESPACE;

    /* Remove leading/trailing whitespace */
    for (i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
            break;
        }
    }
    for (j = strlen(input) - 1; j >= 0; j--) {
        if (isspace(input[j])) {
            input[j] = '\0';
            break;
        }
    }

    /* Remove consecutive whitespace */
    char *sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    sanitized_input[0] = '\0';
    i = 0;
    for (j = 0; j < strlen(input); j++) {
        if (!isspace(input[j])) {
            sanitized_input[i++] = input[j];
        }
    }
    sanitized_input[i] = '\0';

    /* Copy sanitized input to original input */
    strcpy(input, sanitized_input);
    free(sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    /* Get user input */
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Sanitize input */
    sanitize_input(input);

    /* Print sanitized input */
    printf("Sanitized input: %s\n", input);

    return 0;
}