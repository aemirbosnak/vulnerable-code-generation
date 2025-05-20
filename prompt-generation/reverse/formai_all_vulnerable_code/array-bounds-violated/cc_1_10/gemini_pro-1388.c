//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Error codes
enum errors {
    NO_ERROR = 0,
    FILE_NOT_FOUND = 1,
    INVALID_ARGUMENT = 2,
    OUT_OF_MEMORY = 3,
    IO_ERROR = 4,
    ALL_GOOD = 100
};

// Error messages
const char *error_messages[] = {
    "No error",
    "File not found",
    "Invalid argument",
    "Out of memory",
    "I/O error",
    "All good!"
};

// Function to handle errors
void handle_error(int error_code) {
    printf("%s\n", error_messages[error_code]);
    exit(error_code);
}

// Main function
int main() {
    int error_code = NO_ERROR;

    // Try to open a file
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        error_code = FILE_NOT_FOUND;
        handle_error(error_code);
    }

    // Try to read from the file
    char buffer[100];
    if (fgets(buffer, 100, file) == NULL) {
        error_code = IO_ERROR;
        handle_error(error_code);
    }

    // Try to close the file
    if (fclose(file) != 0) {
        error_code = IO_ERROR;
        handle_error(error_code);
    }

    // If we get here, everything went well
    error_code = ALL_GOOD;
    handle_error(error_code);

    return 0;
}