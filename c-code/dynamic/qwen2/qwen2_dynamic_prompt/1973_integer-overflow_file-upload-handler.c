#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void handle_file_upload(char *filename) {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    // Simulate file opening
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading file content
    bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    // Integer overflow vulnerability
    int buffer_size = bytes_read + 1; // Vulnerable line
    char *new_buffer = (char *)malloc(buffer_size); // Allocate memory based on user input

    if (new_buffer == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // Copy data to new buffer
    memcpy(new_buffer, buffer, bytes_read);
    new_buffer[bytes_read] = '\0';

    // Process the file content
    printf("File content: %s\n", new_buffer);

    free(new_buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1]);

    return 0;
}
