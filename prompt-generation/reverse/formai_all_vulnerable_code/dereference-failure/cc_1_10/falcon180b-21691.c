//Falcon-180B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ERRORS 100

// Define an error structure
typedef struct {
    char *message;
    int line_number;
} Error;

// Define an error handling function
void handle_error(char *message, int line_number) {
    printf("Error: %s (line %d)\n", message, line_number);
    exit(1);
}

// Define a function to push an error onto the stack
void push_error(Error *error_stack, int num_errors, char *message, int line_number) {
    if (num_errors >= MAX_NUM_ERRORS) {
        handle_error("Too many errors", 0);
    }
    error_stack[num_errors].message = message;
    error_stack[num_errors].line_number = line_number;
    num_errors++;
}

// Define a function to pop an error off the stack
void pop_error(Error *error_stack, int *num_errors) {
    (*num_errors)--;
}

// Define a function to check if the error stack is empty
int is_error_stack_empty(Error *error_stack, int num_errors) {
    return num_errors == 0;
}

int main() {
    int num_errors = 0;
    Error error_stack[MAX_NUM_ERRORS];

    // Test pushing errors onto the stack
    push_error(error_stack, num_errors, "This is an error", __LINE__);
    push_error(error_stack, num_errors, "So is this", __LINE__);

    // Test popping errors off the stack
    pop_error(error_stack, &num_errors);

    // Test checking if the error stack is empty
    if (is_error_stack_empty(error_stack, num_errors)) {
        printf("Error stack is empty\n");
    }

    // Test pushing too many errors onto the stack
    for (int i = 0; i < MAX_NUM_ERRORS + 1; i++) {
        push_error(error_stack, num_errors, "This should not be allowed", __LINE__);
    }

    return 0;
}