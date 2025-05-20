//Falcon-180B DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1024

// Function prototypes
int read_file(const char* filename, char** buffer);
void handle_error(const char* error_message);

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        handle_error("Invalid number of arguments.");
        return 1;
    }

    char* buffer = NULL;
    int buffer_size = 0;
    int ret = read_file(argv[1], &buffer);
    if (ret!= 0) {
        handle_error("Error reading file.");
        return 1;
    }

    // Do something with the file content
    printf("File content:\n%s\n", buffer);

    free(buffer);
    return 0;
}

int read_file(const char* filename, char** buffer) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Get file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    *buffer = malloc(file_size + 1);
    if (*buffer == NULL) {
        return -1;
    }

    size_t bytes_read = fread(*buffer, 1, file_size, fp);
    if (bytes_read!= file_size) {
        free(*buffer);
        return -1;
    }

    (*buffer)[bytes_read] = '\0';
    fclose(fp);
    return 0;
}

void handle_error(const char* error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
    exit(1);
}