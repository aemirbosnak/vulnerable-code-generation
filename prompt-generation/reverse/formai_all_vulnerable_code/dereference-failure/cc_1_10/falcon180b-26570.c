//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_INPUT_LENGTH 1024

typedef struct {
    char *input;
    size_t length;
} Input;

bool is_valid_input(const Input *input) {
    if (input == NULL) {
        return false;
    }

    const char *invalid_chars = "\"'!@#$%^&*()_+=-[]{}\\|;:,.<>?/~`";
    size_t invalid_chars_length = strlen(invalid_chars);

    for (size_t i = 0; i < input->length; i++) {
        if (strchr(invalid_chars, input->input[i])!= NULL) {
            return false;
        }
    }

    return true;
}

Input *get_input(const char *prompt) {
    Input *input = malloc(sizeof(Input));

    if (input == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for input.\n");
        exit(EXIT_FAILURE);
    }

    input->input = malloc(MAX_INPUT_LENGTH);

    if (input->input == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for input string.\n");
        exit(EXIT_FAILURE);
    }

    input->length = 0;

    printf("%s", prompt);

    char c;
    while ((c = getchar())!= '\n') {
        if (input->length >= MAX_INPUT_LENGTH) {
            fprintf(stderr, "Error: Input exceeds maximum length.\n");
            exit(EXIT_FAILURE);
        }

        if (isprint(c)) {
            input->input[input->length++] = c;
        } else {
            printf("Invalid character: %c\n", c);
        }
    }

    if (!is_valid_input(input)) {
        fprintf(stderr, "Error: Input contains invalid characters.\n");
        exit(EXIT_FAILURE);
    }

    input->input[input->length] = '\0';

    return input;
}

void free_input(Input *input) {
    if (input!= NULL) {
        free(input->input);
        free(input);
    }
}

int main() {
    Input *input = get_input("Enter your name: ");

    printf("Hello, %s!\n", input->input);

    free_input(input);

    return 0;
}