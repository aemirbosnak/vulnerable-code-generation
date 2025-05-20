#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} FileChunk;

void read_file_chunk(FileChunk *chunk, const char *filename, size_t offset) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, offset, SEEK_SET);
    chunk->data = malloc(BUFFER_SIZE);
    if (!chunk->data) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(chunk->data, 1, BUFFER_SIZE, file);
    if (bytes_read == 0 && ferror(file)) {
        perror("Error reading file");
        free(chunk->data);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    chunk->data[bytes_read] = '\0';
    fclose(file);
}

void write_file_chunk(const FileChunk *chunk, const char *filename, size_t offset) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, offset, SEEK_SET);
    size_t bytes_written = fwrite(chunk->data, 1, strlen(chunk->data), file);
    if (bytes_written != strlen(chunk->data)) {
        perror("Error writing file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main() {
    FileChunk chunk;
    read_file_chunk(&chunk, "source.txt", 0);

    // Simulate a forgotten memory issue by not freeing the allocated memory
    // write_file_chunk(&chunk, "destination.txt", 0); // Uncommenting this line would cause a segmentation fault

    return 0;
}
