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

    if (fseek(file, offset, SEEK_SET) != 0) {
        perror("Failed to seek in file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    chunk->data = malloc(length);
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

    fclose(file);
}

void process_file_chunk(FileChunk *chunk) {
    // Simulate processing by printing the first character
    if (chunk->data && chunk->data[0]) {
        printf("Processing chunk: %c\n", chunk->data[0]);
    } else {
        fprintf(stderr, "Invalid data in chunk\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <offset>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    size_t offset = strtoul(argv[2], NULL, 10);

    FileChunk chunk;
    read_file_chunk(&chunk, filename, offset, BUFFER_SIZE);

    // Intentionally causing a dereference failure
    process_file_chunk(NULL); // Passing a null pointer

    free(chunk.data);
    return EXIT_SUCCESS;
}
