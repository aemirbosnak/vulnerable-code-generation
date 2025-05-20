//Code Llama-13B DATASET v1.0 Category: Syntax parsing ; Style: active
/*
 * Program to parse C syntax
 *
 * Example program in an active style
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000

// Function to parse C syntax
void parse_c_syntax(char *input) {
    // Declare variables
    char *token;
    int i, j;
    char *output[100];

    // Split input into tokens
    token = strtok(input, " ");
    while (token != NULL) {
        output[i++] = token;
        token = strtok(NULL, " ");
    }

    // Check for keywords
    for (j = 0; j < i; j++) {
        if (strcmp(output[j], "if") == 0 || strcmp(output[j], "else") == 0 || strcmp(output[j], "while") == 0 || strcmp(output[j], "for") == 0 || strcmp(output[j], "do") == 0 || strcmp(output[j], "switch") == 0 || strcmp(output[j], "case") == 0 || strcmp(output[j], "default") == 0) {
            printf("%s is a keyword\n", output[j]);
        }
    }

    // Check for identifiers
    for (j = 0; j < i; j++) {
        if (isalpha(output[j][0]) || output[j][0] == '_') {
            printf("%s is an identifier\n", output[j]);
        }
    }

    // Check for integers
    for (j = 0; j < i; j++) {
        if (isdigit(output[j][0])) {
            printf("%s is an integer\n", output[j]);
        }
    }
}

// Main function
int main() {
    // Declare variables
    char input[MAX_INPUT_SIZE];

    // Get input from user
    printf("Enter C syntax: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Parse C syntax
    parse_c_syntax(input);

    return 0;
}