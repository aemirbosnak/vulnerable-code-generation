//Falcon-180B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a macro for error handling
#define ERR_EXIT(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

// Function to open a file
FILE *open_file(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        ERR_EXIT("Error opening file");
    }
    return fp;
}

// Function to read data from a file
int read_data(FILE *fp, void *buffer, size_t count) {
    int bytes_read = fread(buffer, sizeof(char), count, fp);
    if (bytes_read!= count) {
        ERR_EXIT("Error reading data from file");
    }
    return bytes_read;
}

// Function to write data to a file
int write_data(FILE *fp, const void *buffer, size_t count) {
    int bytes_written = fwrite(buffer, sizeof(char), count, fp);
    if (bytes_written!= count) {
        ERR_EXIT("Error writing data to file");
    }
    return bytes_written;
}

// Function to close a file
void close_file(FILE *fp) {
    if (fclose(fp)!= 0) {
        ERR_EXIT("Error closing file");
    }
}

int main() {
    FILE *input_file = open_file("input.txt", "r");
    FILE *output_file = open_file("output.txt", "w");

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = read_data(input_file, buffer, sizeof(buffer))) > 0) {
        if (write_data(output_file, buffer, bytes_read)!= bytes_read) {
            ERR_EXIT("Error copying data");
        }
    }

    close_file(input_file);
    close_file(output_file);

    return 0;
}