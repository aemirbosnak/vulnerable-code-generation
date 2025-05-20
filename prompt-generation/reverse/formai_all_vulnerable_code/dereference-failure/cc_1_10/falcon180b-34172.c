//Falcon-180B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LINE_SIZE 1024

// Function prototypes
int open_file(const char*, int);
void close_file(int);
int read_line(int, char*, int);
void print_error(const char*, int, const char*);

int main() {
    int file_descriptor;
    char line[MAX_LINE_SIZE];
    int line_number = 1;

    file_descriptor = open_file("example.txt", O_RDONLY);
    if (file_descriptor == -1) {
        print_error("Error opening file", errno, "example.txt");
        return EXIT_FAILURE;
    }

    while (read_line(file_descriptor, line, MAX_LINE_SIZE)!= -1) {
        printf("Line %d: %s", line_number, line);
        line_number++;
    }

    close_file(file_descriptor);
    return EXIT_SUCCESS;
}

// Open a file with the given mode and return its file descriptor
int open_file(const char* filename, int mode) {
    int file_descriptor = open(filename, mode);
    if (file_descriptor == -1) {
        print_error("Error opening file", errno, filename);
        return -1;
    }
    return file_descriptor;
}

// Close a file with the given file descriptor
void close_file(int file_descriptor) {
    if (close(file_descriptor) == -1) {
        print_error("Error closing file", errno, "");
    }
}

// Read a line from a file with the given file descriptor and maximum line size
int read_line(int file_descriptor, char* line, int max_line_size) {
    ssize_t bytes_read = getline(&line, &max_line_size, file_descriptor);
    if (bytes_read == -1) {
        print_error("Error reading line", errno, "");
        return -1;
    }
    return bytes_read;
}

// Print an error message with the given error message, error number, and file name
void print_error(const char* error_message, int error_number, const char* file_name) {
    fprintf(stderr, "%s: %s (%d): %s\n", error_message, strerror(error_number), error_number, file_name);
}