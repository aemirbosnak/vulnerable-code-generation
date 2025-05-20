//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error code enumeration
typedef enum {
    ERR_OK = 0,
    ERR_INVALID_ARG,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_READ_ERROR,
    ERR_FILE_WRITE_ERROR,
    ERR_MEMORY_ALLOCATION_FAILED,
    ERR_INVALID_OPERATION,
    ERR_INVALID_DATA_TYPE,
    ERR_INVALID_FILE_FORMAT,
    ERR_INVALID_STATE,
    ERR_INVALID_VALUE,
    ERR_UNSUPPORTED_FEATURE,
    ERR_SYSTEM_ERROR
} ErrorCode;

// Error message structure
typedef struct {
    ErrorCode code;
    char *message;
} ErrorMsg;

// Error handling function
void error_handler(ErrorCode code, char *message) {
    printf("Error: %s\n", message);
    exit(code);
}

// Example function that may cause errors
int read_data_from_file(char *filename, int *data) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        error_handler(ERR_FILE_NOT_FOUND, "File not found");
    }

    int count = fscanf(fp, "%d", data);
    if (count!= 1) {
        error_handler(ERR_INVALID_DATA_TYPE, "Invalid data type");
    }

    fclose(fp);
    return count;
}

// Example usage of error handling
int main() {
    int data = 0;
    char filename[] = "data.txt";

    int result = read_data_from_file(filename, &data);
    if (result == ERR_OK) {
        printf("Data read from file: %d\n", data);
    }

    return 0;
}