//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 256

void sanitize_input(char *input, size_t size) {
    int i, j;
    bool is_valid = true;

    // Remove leading and trailing whitespaces
    for (i = 0; i < size && isspace((unsigned char)input[i]); i++);
    for (size_t k = size; k-- && isspace((unsigned char)input[k]); );
    size_t len = size - i;

    // Check for SQL injection and XSS attacks
    for (i = 0; i < len && is_valid; i++) {
        if (input[i] == '\'' || input[i] == '<' || input[i] == '>') {
            if (i > 0 && (input[i - 1] == '\\' || isspace((unsigned char)input[i - 1])))
                continue;
            if (len - i >= 2 && (input[i + 1] == '>' || input[i + 1] == '\''))
                continue;
            is_valid = false;
            break;
        }
    }

    if (!is_valid) {
        printf("Invalid input: %s\n", input);
        exit(EXIT_FAILURE);
    }

    // Remove invalid characters
    for (i = 0, j = 0; i < size && j < BUFFER_SIZE; i++, j++) {
        if (isalnum((unsigned char)input[i]) || input[i] == '_' || input[i] == ' ') {
            input[j] = input[i];
        }
    }
    input[j] = '\0';
}

int main(int argc, char **argv) {
    char input[MAX_INPUT_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(input, argv[1], MAX_INPUT_SIZE);
    sanitize_input(input, strlen(input));

    printf("Sanitized input: %s\n", input);

    return EXIT_SUCCESS;
}