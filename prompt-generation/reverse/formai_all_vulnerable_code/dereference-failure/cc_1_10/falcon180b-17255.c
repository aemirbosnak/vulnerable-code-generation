//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

typedef struct {
    char *input;
    size_t length;
} Input;

void init_input(Input *input) {
    input->input = NULL;
    input->length = 0;
}

void destroy_input(Input *input) {
    free(input->input);
    input->input = NULL;
    input->length = 0;
}

void sanitize_input(Input *input) {
    size_t i;
    for (i = 0; i < input->length; i++) {
        if (!isalnum(input->input[i])) {
            input->input[i] = '_';
        }
    }
}

void print_input(Input *input) {
    printf("Input: %s\n", input->input);
}

int main(int argc, char *argv[]) {
    Input input;
    init_input(&input);

    char buffer[MAX_INPUT_LENGTH];
    printf("Enter some input: ");
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    input.input = strdup(buffer);
    input.length = strlen(input.input);

    sanitize_input(&input);
    printf("Sanitized input: ");
    print_input(&input);

    destroy_input(&input);

    return 0;
}