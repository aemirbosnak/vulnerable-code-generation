#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    FILE *file;
    size_t bytes_read;

    // Simulate reading the filename from user input
    strncpy(buffer, filename, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    // Attempt to open the file
    file = fopen(buffer, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Allocate memory for file content
    char *content = malloc(1024);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    // Read file content into buffer
    bytes_read = fread(content, 1, 1024, file);

    // Intentionally read past the allocated memory
    printf("File content: %.*s\n", (int)bytes_read + 10, content); // Out of bounds read

    free(content);
    fclose(file);
}

int main() {
    const char *filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
