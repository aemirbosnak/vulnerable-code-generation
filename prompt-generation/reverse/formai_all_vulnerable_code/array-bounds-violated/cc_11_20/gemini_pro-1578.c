//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    int i;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove any leading or trailing whitespace
    while (input[0] == ' ') {
        memmove(input, input + 1, strlen(input));
    }
    while (input[strlen(input) - 1] == ' ') {
        input[strlen(input) - 1] = '\0';
    }

    // Check for invalid characters
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i]) && input[i] != ' ') {
            printf("Invalid character: %c\n", input[i]);
            return 1;
        }
    }

    // Check for excessive whitespace
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' && input[i + 1] == ' ') {
            printf("Excessive whitespace\n");
            return 1;
        }
    }

    // Check for leading or trailing whitespace
    if (input[0] == ' ' || input[strlen(input) - 1] == ' ') {
        printf("Leading or trailing whitespace\n");
        return 1;
    }

    // Check for minimum length
    if (strlen(input) < 5) {
        printf("Input is too short\n");
        return 1;
    }

    // Check for maximum length
    if (strlen(input) > MAX_INPUT_LENGTH) {
        printf("Input is too long\n");
        return 1;
    }

    // Input is valid
    printf("Input is valid\n");

    return 0;
}