//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Custom error codes
enum ErrorCodes {
    SUCCESS = 0,
    INVALID_INPUT = 1,
    MEMORY_ALLOCATION_FAILED = 2,
    FILE_NOT_FOUND = 3,
    IO_ERROR = 4
};

// Function to print error messages based on error codes
void printErrorMessage(enum ErrorCodes errorCode) {
    switch (errorCode) {
        case SUCCESS:
            printf("No errors encountered.\n");
            break;
        case INVALID_INPUT:
            printf("Invalid input provided.\n");
            break;
        case MEMORY_ALLOCATION_FAILED:
            printf("Memory allocation failed.\n");
            break;
        case FILE_NOT_FOUND:
            printf("File not found.\n");
            break;
        case IO_ERROR:
            printf("Input/output error occurred.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
    }
}

// Function to demonstrate error handling
int main() {
    // Declare variables
    int *ptr = NULL;
    FILE *fp = NULL;
    char *filename = "non-existent-file.txt";
    int value;

    // Attempt to allocate memory
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printErrorMessage(MEMORY_ALLOCATION_FAILED);
        return EXIT_FAILURE;
    }

    // Attempt to open a file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printErrorMessage(FILE_NOT_FOUND);
        free(ptr); // Release allocated memory
        return EXIT_FAILURE;
    }

    // Attempt to read a value from the file
    if (fscanf(fp, "%d", &value) != 1) {
        printErrorMessage(IO_ERROR);
        fclose(fp); // Close the file
        free(ptr); // Release allocated memory
        return EXIT_FAILURE;
    }

    // Print the value
    printf("Value read from file: %d\n", value);

    // Close the file
    fclose(fp);

    // Release allocated memory
    free(ptr);

    // Return success
    return EXIT_SUCCESS;
}