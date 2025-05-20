//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int i, valid = 1;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Check for empty input
    if (strlen(input) == 1) {
        printf("Invalid input: Empty string\n");
        valid = 0;
    }

    // Check for non-printable characters
    for (i = 0; input[i] != '\0'; i++) {
        if (!isprint(input[i])) {
            printf("Invalid input: Non-printable character found\n");
            valid = 0;
            break;
        }
    }

    // Check for invalid characters
    for (i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i]) && input[i] != ' ' && input[i] != '-') {
            printf("Invalid input: Invalid character found\n");
            valid = 0;
            break;
        }
    }

    // Check for leading or trailing spaces
    if (isspace(input[0]) || isspace(input[strlen(input) - 1])) {
        printf("Invalid input: Leading or trailing spaces found\n");
        valid = 0;
    }

    // Check for multiple consecutive spaces
    for (i = 1; input[i] != '\0'; i++) {
        if (isspace(input[i]) && isspace(input[i - 1])) {
            printf("Invalid input: Multiple consecutive spaces found\n");
            valid = 0;
            break;
        }
    }

    // Check for leading or trailing hyphens
    if (input[0] == '-' || input[strlen(input) - 1] == '-') {
        printf("Invalid input: Leading or trailing hyphens found\n");
        valid = 0;
    }

    // Check for multiple consecutive hyphens
    for (i = 1; input[i] != '\0'; i++) {
        if (input[i] == '-' && input[i - 1] == '-') {
            printf("Invalid input: Multiple consecutive hyphens found\n");
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("Valid input: \"%s\"\n", input);
    }

    return 0;
}