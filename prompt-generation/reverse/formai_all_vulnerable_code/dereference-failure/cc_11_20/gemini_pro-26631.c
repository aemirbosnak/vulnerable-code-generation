//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 10

char *tokens[MAX_TOKENS];
int num_tokens = 0;

int main() {
    char input[MAX_INPUT_SIZE];
    char *pch;

    // Get user input
    printf("Enter input (max %d characters): ", MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Tokenize input
    pch = strtok(input, " ");
    while (pch != NULL && num_tokens < MAX_TOKENS) {
        tokens[num_tokens++] = strdup(pch);
        pch = strtok(NULL, " ");
    }

    // Sanitize input
    for (int i = 0; i < num_tokens; i++) {
        // Check for invalid characters
        for (char *c = tokens[i]; *c != '\0'; c++) {
            if (!isalnum(*c) && *c != '_' && *c != '-') {
                printf("Invalid character '%c' in token '%s'\n", *c, tokens[i]);
                exit(1);
            }
        }

        // Check for reserved keywords
        if (strcmp(tokens[i], "if") == 0 || strcmp(tokens[i], "else") == 0 ||
            strcmp(tokens[i], "while") == 0 || strcmp(tokens[i], "for") == 0 ||
            strcmp(tokens[i], "int") == 0 || strcmp(tokens[i], "float") == 0 ||
            strcmp(tokens[i], "char") == 0) {
            printf("Reserved keyword '%s' not allowed\n", tokens[i]);
            exit(1);
        }
    }

    // Print sanitized input
    printf("Sanitized input:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    return 0;
}