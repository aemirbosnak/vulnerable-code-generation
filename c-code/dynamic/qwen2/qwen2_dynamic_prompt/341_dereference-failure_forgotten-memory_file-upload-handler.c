#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_FILENAME_LENGTH];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    // Simulate processing the file content
    printf("Processing %zu bytes from file: %s\n", bytes_read, filename);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // Deliberate dereference failure (forgotten memory)
    char *temp_filename = NULL;
    strcpy(temp_filename, filename); // This line causes the vulnerability

    handle_file_upload(temp_filename);

    free(temp_filename); // This line should not be reached due to the vulnerability

    return 0;
}
