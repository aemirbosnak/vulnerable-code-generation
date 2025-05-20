//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;
    char *output = malloc(MAX_LENGTH * sizeof(char));
    int output_length = 0;

    // Remove leading and trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        input[strlen(input) - 1] = '\0';
    }

    // Convert all characters to lowercase
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            output[output_length++] = tolower(input[i]);
        }
    }

    // Add null terminator
    output[output_length] = '\0';

    // Copy sanitized input to original input
    strcpy(input, output);
    free(output);
}

int main() {
    char input[MAX_LENGTH];

    // Prompt user for input
    printf("Enter some text: ");
    fgets(input, MAX_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}