//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Custom error codes
enum my_error_codes {
    MY_ERROR_INVALID_ARGUMENT = 1,
    MY_ERROR_FILE_NOT_FOUND = 2,
    MY_ERROR_IO_ERROR = 3,
    // Add more custom error codes here...
};

// Custom error handling function
void my_error_handler(int error_code) {
    switch (error_code) {
        case MY_ERROR_INVALID_ARGUMENT:
            fprintf(stderr, "Invalid argument provided.\n");
            exit(EXIT_FAILURE);
        case MY_ERROR_FILE_NOT_FOUND:
            fprintf(stderr, "File not found.\n");
            exit(EXIT_FAILURE);
        case MY_ERROR_IO_ERROR:
            fprintf(stderr, "IO error occurred.\n");
            exit(EXIT_FAILURE);
        // Add more error handling cases here...
        default:
            fprintf(stderr, "Unknown error occurred.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    // Open a file
    FILE *fp = fopen("myfile.txt", "r");
    if (fp == NULL) {
        my_error_handler(MY_ERROR_FILE_NOT_FOUND);
    }

    // Read a line from the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        my_error_handler(MY_ERROR_IO_ERROR);
    }

    // Close the file
    if (fclose(fp) != 0) {
        my_error_handler(MY_ERROR_IO_ERROR);
    }

    // Parse the line
    int value;
    if (sscanf(line, "%d", &value) != 1) {
        my_error_handler(MY_ERROR_INVALID_ARGUMENT);
    }

    // Use the value
    printf("The value is: %d\n", value);

    return EXIT_SUCCESS;
}