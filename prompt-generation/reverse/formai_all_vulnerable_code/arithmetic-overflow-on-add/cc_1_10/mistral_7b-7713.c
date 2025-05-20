//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

void sanitize_string(char *input, int length, int *index);
char sanitized_char(char c);

int main() {
    char input[MAX_INPUT_LENGTH];
    int length = 0;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from fgets
    input[strcspn(input, "\n")] = '\0';

    length = strlen(input);

    printf("Sanitizing input of length %d...\n", length);

    sanitize_string(input, length, 0);
    printf("Sanitized input: %s\n", input);

    return 0;
}

void sanitize_string(char *input, int length, int *index) {
    if (*index >= length) {
        return;
    }

    char c = input[*index];

    if (isalnum(c) || c == ' ' || c == '\'' || c == '&' || c == '#' || c == '*' || c == '+' || c == '-' || c == '.' || c == '_' || c == '/') {
        (*index)++;
        sanitize_string(input, length, index);
    } else {
        input[*index] = sanitized_char(c);
        (*index)++;
        sanitize_string(input, length, index);
    }
}

char sanitized_char(char c) {
    switch (c) {
        case '\'':
            return '\'';
        case '&':
            return '&amp;';
        case '#':
            return '&#';
        case '*':
            return '&ast;';
        case '+':
            return '&plus;';
        case '-':
            return '&ndash;';
        case '.':
            return '&period;';
        case '_':
            return '& underscore;';
        case '/':
            return '&sol;';
        default:
            if (isalnum(c) || c == ' ' || c == '\'' || c == '\n') {
                return c;
            } else {
                return '_';
            }
    }
}