//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024

typedef struct {
    char *input;
    int length;
} Input;

Input *create_input() {
    Input *input = malloc(sizeof(Input));
    input->input = malloc(MAX_INPUT_LENGTH);
    input->length = 0;
    return input;
}

void destroy_input(Input *input) {
    free(input->input);
    free(input);
}

void append_char(Input *input, char c) {
    if (input->length >= MAX_INPUT_LENGTH) {
        printf("Error: Input is too long.\n");
        exit(1);
    }
    input->input[input->length++] = c;
}

void clear_input(Input *input) {
    input->length = 0;
}

bool is_input_empty(Input *input) {
    return input->length == 0;
}

void sanitize_input(Input *input) {
    for (int i = 0; i < input->length; i++) {
        if (!isalnum(input->input[i])) {
            printf("Error: Input contains invalid characters.\n");
            exit(1);
        }
    }
}

int main() {
    Input *input = create_input();
    char c;

    while (true) {
        printf("Enter your input (up to %d characters): ", MAX_INPUT_LENGTH - 1);
        fflush(stdout);
        c = getchar();

        if (c == '\n') {
            break;
        }

        if (isalnum(c)) {
            append_char(input, c);
        } else if (c == '\b') {
            if (!is_input_empty(input)) {
                clear_input(input);
                printf("\b \b");
            }
        } else {
            printf("Error: Invalid character.\n");
            exit(1);
        }
    }

    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input->input);

    destroy_input(input);
    return 0;
}