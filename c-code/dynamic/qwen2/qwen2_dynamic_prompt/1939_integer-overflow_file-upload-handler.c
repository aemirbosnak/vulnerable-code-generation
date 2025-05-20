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
    size_t file_size;

    // Simulate file opening
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return;
    }

    // Read file content into buffer
    file_size = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    // Deliberate integer overflow vulnerability
    int new_size = (int)(file_size + MAX_FILE_SIZE); // Overflow here

    // Allocate memory based on potentially overflowed value
    char *new_buffer = (char *)malloc(new_size);
    if (new_buffer == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // Copy original data to new buffer
    memcpy(new_buffer, buffer, file_size);

    // Use the new buffer (this is just a placeholder)
    printf("File content: %s\n", new_buffer);

    // Free allocated memory
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
