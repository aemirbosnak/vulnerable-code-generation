//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;
    char sanitized_input[MAX_INPUT_LENGTH];
    sanitized_input[0] = '\0';

    // Remove leading/trailing white spaces
    for (i = 0; i < strlen(input); i++) {
        if (!isspace(input[i])) {
            strncat(sanitized_input, &input[i], 1);
        }
    }

    // Remove consecutive white spaces
    for (i = 0; i < strlen(sanitized_input); i++) {
        if (isspace(sanitized_input[i])) {
            for (j = i; j < strlen(sanitized_input); j++) {
                sanitized_input[j] = sanitized_input[j+1];
            }
            sanitized_input[strlen(sanitized_input)-1] = '\0';
            i--;
        }
    }

    // Remove special characters
    for (i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '_';
        }
    }

    // Copy sanitized input to original input
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Welcome to the year 2050!\n");
    printf("Please enter your name:\n");
    scanf("%s", input);

    // Sanitize user input
    sanitize_input(input);

    printf("Hello, %s!\n", input);

    return 0;
}