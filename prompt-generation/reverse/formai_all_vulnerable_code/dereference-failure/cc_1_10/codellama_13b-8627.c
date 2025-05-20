//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: ultraprecise
// Error Handling Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error codes
#define E_SUCCESS 0
#define E_MEMORY_ALLOC_FAILED 1
#define E_INVALID_ARGUMENT 2
#define E_FILE_OPEN_FAILED 3
#define E_FILE_READ_FAILED 4
#define E_FILE_WRITE_FAILED 5

// Structure to hold error details
typedef struct {
    int code;
    char message[100];
} Error;

// Function to handle errors
void handle_error(Error error) {
    printf("Error: %s (%d)\n", error.message, error.code);
    exit(error.code);
}

// Function to allocate memory
void* allocate_memory(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        Error error = { E_MEMORY_ALLOC_FAILED, "Memory allocation failed" };
        handle_error(error);
    }
    return ptr;
}

// Function to open a file
FILE* open_file(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        Error error = { E_FILE_OPEN_FAILED, "File open failed" };
        handle_error(error);
    }
    return file;
}

// Function to read from a file
int read_file(FILE* file, void* buffer, size_t size) {
    int bytes_read = fread(buffer, 1, size, file);
    if (bytes_read != size) {
        Error error = { E_FILE_READ_FAILED, "File read failed" };
        handle_error(error);
    }
    return bytes_read;
}

// Function to write to a file
int write_file(FILE* file, const void* buffer, size_t size) {
    int bytes_written = fwrite(buffer, 1, size, file);
    if (bytes_written != size) {
        Error error = { E_FILE_WRITE_FAILED, "File write failed" };
        handle_error(error);
    }
    return bytes_written;
}

// Function to check if a file exists
int file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fclose(file);
    return 1;
}

int main(int argc, char* argv[]) {
    // Check if the input file exists
    if (!file_exists(argv[1])) {
        Error error = { E_INVALID_ARGUMENT, "Input file does not exist" };
        handle_error(error);
    }

    // Open the input file
    FILE* input_file = open_file(argv[1], "r");

    // Allocate memory for the input file contents
    size_t input_size = 100;
    char* input_buffer = allocate_memory(input_size);

    // Read the input file contents
    int bytes_read = read_file(input_file, input_buffer, input_size);
    if (bytes_read == 0) {
        Error error = { E_FILE_READ_FAILED, "Input file is empty" };
        handle_error(error);
    }

    // Close the input file
    fclose(input_file);

    // Open the output file
    FILE* output_file = open_file("output.txt", "w");

    // Write the input file contents to the output file
    int bytes_written = write_file(output_file, input_buffer, input_size);
    if (bytes_written == 0) {
        Error error = { E_FILE_WRITE_FAILED, "Output file is empty" };
        handle_error(error);
    }

    // Close the output file
    fclose(output_file);

    // Free the input file contents
    free(input_buffer);

    return E_SUCCESS;
}