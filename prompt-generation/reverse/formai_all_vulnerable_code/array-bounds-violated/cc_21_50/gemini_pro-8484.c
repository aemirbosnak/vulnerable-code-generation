//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 1024

int main() {
    char input[MAX_INPUT_LEN];
    char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    char *disallowed_chars = "~!@#$%^&*()_+=-`[]\\;',./<>?\"";
    int i, j;

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Check for null-terminator
    if (input[strlen(input) - 1] != '\0') {
        printf("Error: Input is too long.\n");
        return 1;
    }

    // Check for empty input
    if (strlen(input) == 0) {
        printf("Error: Input is empty.\n");
        return 1;
    }

    // Check for invalid characters
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < strlen(disallowed_chars); j++) {
            if (input[i] == disallowed_chars[j]) {
                printf("Error: Input contains invalid characters.\n");
                return 1;
            }
        }
    }

    // Check for whitespace-only input
    if (strspn(input, allowed_chars) == 0) {
        printf("Error: Input is whitespace-only.\n");
        return 1;
    }

    // Check for leading and trailing whitespace
    if (isspace(input[0]) || isspace(input[strlen(input) - 1])) {
        printf("Error: Input contains leading or trailing whitespace.\n");
        return 1;
    }

    // Check for consecutive whitespace
    for (i = 0; i < strlen(input) - 1; i++) {
        if (isspace(input[i]) && isspace(input[i + 1])) {
            printf("Error: Input contains consecutive whitespace.\n");
            return 1;
        }
    }

    // Check for non-breaking spaces
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == 0xC2 && input[i + 1] == 0xA0) {
            printf("Error: Input contains non-breaking spaces.\n");
            return 1;
        }
    }

    // Check for tabs
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\t') {
            printf("Error: Input contains tabs.\n");
            return 1;
        }
    }

    // Check for newlines
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            printf("Error: Input contains newlines.\n");
            return 1;
        }
    }

    // Check for carriage returns
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\r') {
            printf("Error: Input contains carriage returns.\n");
            return 1;
        }
    }

    // Check for control characters
    for (i = 0; i < strlen(input); i++) {
        if (iscntrl(input[i])) {
            printf("Error: Input contains control characters.\n");
            return 1;
        }
    }

    // All checks passed, input is valid
    printf("Input is valid.\n");
    return 0;
}