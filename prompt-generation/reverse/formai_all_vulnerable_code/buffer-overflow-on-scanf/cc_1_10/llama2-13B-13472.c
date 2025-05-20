//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ERROR_MESSAGE_SIZE 256

typedef enum {
    SUCCESS,
    FAILED,
    INVALID_INPUT,
    OUT_OF_BOUNDS,
    DIVIDE_BY_ZERO,
    UNKNOWN_ERROR
} ErrorType;

static void handleError(ErrorType errorType, const char* message) {
    switch (errorType) {
        case SUCCESS:
            break; // do nothing
        case FAILED:
            fprintf(stderr, "Error: %s\n", message);
            break;
        case INVALID_INPUT:
            fprintf(stderr, "Invalid input: %s\n", message);
            break;
        case OUT_OF_BOUNDS:
            fprintf(stderr, "Out of bounds: %s\n", message);
            break;
        case DIVIDE_BY_ZERO:
            fprintf(stderr, "Divide by zero: %s\n", message);
            break;
        case UNKNOWN_ERROR:
            fprintf(stderr, "Unknown error: %s\n", message);
            break;
        default:
            fprintf(stderr, "Unhandled error: %s\n", message);
            break;
    }
    exit(EXIT_FAILURE);
}

int main() {
    int input;
    char buffer[MAX_INPUT_SIZE];

    // Example 1: Invalid input
    if (scanf("%d", &input) != 1) {
        handleError(INVALID_INPUT, "Invalid input");
    }

    // Example 2: Out of bounds
    if (input > 100) {
        handleError(OUT_OF_BOUNDS, "Input is out of bounds");
    }

    // Example 3: Divide by zero
    if (input == 0) {
        handleError(DIVIDE_BY_ZERO, "Divide by zero");
    }

    // Example 4: Unknown error
    if (input == 42) {
        handleError(UNKNOWN_ERROR, "Unknown error");
    }

    // Example 5: Success
    printf("Success\n");

    return SUCCESS;
}