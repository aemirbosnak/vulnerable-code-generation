//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our own error codes
#define ERR_SUCCESS 0
#define ERR_INVALID_INPUT 1
#define ERR_MEMORY_ALLOCATION_FAILED 2
#define ERR_FILE_OPEN_FAILED 3
#define ERR_FILE_READ_FAILED 4
#define ERR_FILE_WRITE_FAILED 5

// Define our own error messages
const char *error_messages[] = {
    "Success",
    "Invalid input",
    "Memory allocation failed",
    "File open failed",
    "File read failed",
    "File write failed"
};

// Define our own error handling function
int error_handler(int error_code) {
    if (error_code != ERR_SUCCESS) {
        fprintf(stderr, "Error: %s\n", error_messages[error_code]);
        return error_code;
    }
    return ERR_SUCCESS;
}

// Main function
int main() {
    // Declare our variables
    int error_code;
    char *input = NULL;
    FILE *file = NULL;

    // Get input from the user
    printf("Enter a string: ");
    if (getline(&input, NULL, stdin) == -1) {
        error_code = ERR_INVALID_INPUT;
        goto cleanup;
    }

    // Allocate memory for the input string
    input = realloc(input, strlen(input) + 1);
    if (input == NULL) {
        error_code = ERR_MEMORY_ALLOCATION_FAILED;
        goto cleanup;
    }

    // Open the file for writing
    file = fopen("output.txt", "w");
    if (file == NULL) {
        error_code = ERR_FILE_OPEN_FAILED;
        goto cleanup;
    }

    // Write the input string to the file
    if (fwrite(input, strlen(input), 1, file) != 1) {
        error_code = ERR_FILE_WRITE_FAILED;
        goto cleanup;
    }

    // Close the file
    if (fclose(file) != 0) {
        error_code = ERR_FILE_READ_FAILED;
        goto cleanup;
    }

cleanup:
    // Free the allocated memory
    free(input);

    // Close the file if it was opened successfully
    if (file != NULL) {
        fclose(file);
    }

    // Return the error code
    return error_handler(error_code);
}