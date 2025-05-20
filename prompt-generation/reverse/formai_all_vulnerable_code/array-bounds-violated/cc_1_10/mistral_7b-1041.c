//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT_SIZE 100

// List of allowed characters
const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

// Function to check if a character is allowed
int is_allowed_char(char c) {
    int i;
    for (i = 0; i < strlen(allowed_chars); i++) {
        if (tolower(c) == tolower(allowed_chars[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (!is_allowed_char(input[i])) {
            for (j = i; j < strlen(input); j++) {
                input[j] = input[j + 1];
            }
            input[strlen(input) - 1] = '\0';
            printf("Invalid character '%c' detected. Please enter a valid input.\n", input[i]);
            scanf("%s", input);
            i = 0;
        }
    }
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    int i;

    printf("Hello and welcome to SanitizerSherlock, the user input sanitizer!\n");
    printf("Please enter your input (up to %d characters): ", MAX_INPUT_SIZE);
    fgets(user_input, MAX_INPUT_SIZE, stdin);

    // Remove newline character from user input
    user_input[strlen(user_input) - 1] = '\0';

    sanitize_input(user_input);

    printf("Your sanitized input is: %s\n", user_input);

    for (i = 0; i < strlen(user_input); i++) {
        printf("%c", user_input[i]);
    }

    return 0;
}