//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function to handle errors
void error_handling(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Function to read a file
void read_file(const char* filename, char** buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error_handling("Failed to open file");
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    *buffer = malloc(file_size + 1);
    if (*buffer == NULL) {
        error_handling("Failed to allocate memory");
    }

    size_t bytes_read = fread(*buffer, 1, file_size, file);
    if (bytes_read!= file_size) {
        error_handling("Failed to read file");
    }

    (*buffer)[file_size] = '\0';
    fclose(file);
}

// Function to write to a file
void write_file(const char* filename, const char* data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        error_handling("Failed to open file");
    }

    size_t bytes_written = fwrite(data, strlen(data), 1, file);
    if (bytes_written!= 1) {
        error_handling("Failed to write to file");
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        error_handling("Incorrect number of arguments");
    }

    char* input_buffer = NULL;
    read_file(argv[1], &input_buffer);

    char* output_buffer = malloc(strlen(input_buffer) + 1);
    if (output_buffer == NULL) {
        error_handling("Failed to allocate memory");
    }

    strcpy(output_buffer, input_buffer);
    strcat(output_buffer, " - Modified");

    write_file(argv[2], output_buffer);

    free(input_buffer);
    free(output_buffer);

    return EXIT_SUCCESS;
}