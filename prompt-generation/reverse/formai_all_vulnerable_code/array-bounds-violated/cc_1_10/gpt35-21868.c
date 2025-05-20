//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char input[], int length);

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    sanitize_input(input, length);

    printf("Sanitized input: %s\n", input);

    return 0;
}

void sanitize_input(char input[], int length) {
    char sanitized_input[MAX_INPUT_LENGTH];
    int sanitized_index = 0;

    for (int i = 0; i < length; i++) {
        char current_char = input[i];

        // Sanitize special characters
        if (current_char == '<') {
            sanitized_input[sanitized_index++] = '&';
            sanitized_input[sanitized_index++] = 'l';
            sanitized_input[sanitized_index++] = 't';
            sanitized_input[sanitized_index++] = ';';
        } else if (current_char == '>') {
            sanitized_input[sanitized_index++] = '&';
            sanitized_input[sanitized_index++] = 'g';
            sanitized_input[sanitized_index++] = 't';
            sanitized_input[sanitized_index++] = ';';
        } else if (current_char == '&') {
            sanitized_input[sanitized_index++] = '&';
            sanitized_input[sanitized_index++] = 'a';
            sanitized_input[sanitized_index++] = 'm';
            sanitized_input[sanitized_index++] = 'p';
            sanitized_input[sanitized_index++] = ';';
        } else if (current_char == '\"') {
            sanitized_input[sanitized_index++] = '&';
            sanitized_input[sanitized_index++] = 'q';
            sanitized_input[sanitized_index++] = 'u';
            sanitized_input[sanitized_index++] = 'o';
            sanitized_input[sanitized_index++] = 't';
            sanitized_input[sanitized_index++] = ';';
        } else if (current_char == '\'') {
            sanitized_input[sanitized_index++] = '&';
            sanitized_input[sanitized_index++] = '#';
            sanitized_input[sanitized_index++] = '3';
            sanitized_input[sanitized_index++] = '9';
            sanitized_input[sanitized_index++] = ';';
        } else {
            // Copy over other characters
            sanitized_input[sanitized_index++] = current_char;
        }
    }

    // Make sure the sanitized input is null-terminated
    sanitized_input[sanitized_index] = '\0';

    // Copy the sanitized input back into the original input
    strcpy(input, sanitized_input);
}