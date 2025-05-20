#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} FileChunk;

void read_file_chunk(FileChunk *chunk, const char *filename, size_t offset) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, offset, SEEK_SET);
    chunk->length = fread(chunk->data, 1, BUFFER_SIZE, file);
    fclose(file);
}

int main() {
    FileChunk chunk;
    chunk.data = malloc(BUFFER_SIZE);
    if (!chunk.data) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    read_file_chunk(&chunk, "nonexistent_file.txt", 0);

    // Deliberate dereference failure: invalid pointer
    printf("%s\n", chunk.data); // This will cause a segmentation fault

    free(chunk.data);
    return EXIT_SUCCESS;
}
