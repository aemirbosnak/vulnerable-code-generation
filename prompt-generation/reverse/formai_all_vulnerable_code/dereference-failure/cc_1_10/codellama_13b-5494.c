//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MSG_LEN 100

typedef enum {
    ERROR_NONE,
    ERROR_UNKNOWN,
    ERROR_INVALID_ARGUMENT,
    ERROR_FILE_NOT_FOUND,
    ERROR_MEMORY_ALLOCATION_FAILED,
    ERROR_FILE_WRITE_FAILED
} ErrorCode;

typedef struct {
    ErrorCode code;
    char message[MAX_ERROR_MSG_LEN];
} Error;

Error* create_error(ErrorCode code, const char* message) {
    Error* error = malloc(sizeof(Error));
    error->code = code;
    strncpy(error->message, message, MAX_ERROR_MSG_LEN);
    return error;
}

void free_error(Error* error) {
    free(error);
}

void handle_error(Error* error) {
    if (error == NULL) {
        return;
    }
    switch (error->code) {
        case ERROR_NONE:
            printf("No error occurred.\n");
            break;
        case ERROR_UNKNOWN:
            printf("An unknown error occurred.\n");
            break;
        case ERROR_INVALID_ARGUMENT:
            printf("Invalid argument.\n");
            break;
        case ERROR_FILE_NOT_FOUND:
            printf("File not found.\n");
            break;
        case ERROR_MEMORY_ALLOCATION_FAILED:
            printf("Memory allocation failed.\n");
            break;
        case ERROR_FILE_WRITE_FAILED:
            printf("File write failed.\n");
            break;
        default:
            printf("Unknown error code: %d\n", error->code);
            break;
    }
    free_error(error);
}

int main() {
    Error* error = create_error(ERROR_NONE, "No error occurred.");
    handle_error(error);
    return 0;
}