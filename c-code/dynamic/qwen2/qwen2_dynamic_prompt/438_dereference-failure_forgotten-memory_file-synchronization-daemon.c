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

void read_file_chunk(FileChunk *chunk, const char *filename, size_t offset, size_t length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, offset, SEEK_SET);
    chunk->data = malloc(length + 1);
    if (!chunk->data) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(chunk->data, 1, length, file);
    if (bytes_read != length) {
        fprintf(stderr, "Failed to read expected number of bytes\n");
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
        fprintf(stderr, "Failed to write expected number of bytes\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

int main() {
    FileChunk chunk;
    read_file_chunk(&chunk, "source.txt", 0, BUFFER_SIZE);

    // Intentional dereference failure: using freed memory
    printf("%s\n", chunk.data); // This will likely crash due to dangling pointer

    free(chunk.data);

    return 0;
}
