//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;
    char *sanitized_input = malloc(MAX_INPUT_SIZE);
    sanitized_input[0] = '\0';

    // Remove any non-alphanumeric characters
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalnum(input[i])) {
            strncat(sanitized_input, &input[i], 1);
        }
    }

    // Remove any leading/trailing whitespace
    for (i = 0; sanitized_input[i]!= '\0'; i++) {
        if (!isspace(sanitized_input[i])) {
            break;
        }
    }
    for (j = strlen(sanitized_input) - 1; j >= 0; j--) {
        if (!isspace(sanitized_input[j])) {
            sanitized_input[j + 1] = '\0';
            break;
        }
    }

    // Copy sanitized input back to original buffer
    strcpy(input, sanitized_input);
    free(sanitized_input);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize user input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}