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

void process_file_chunks(const char *filename) {
    FileChunk chunks[10];
    size_t total_length = 0;

    // Simulate reading multiple chunks from a file
    for (size_t i = 0; i < 10; ++i) {
        read_file_chunk(&chunks[i], filename, total_length, BUFFER_SIZE);
        total_length += BUFFER_SIZE;
    }

    // Process each chunk (simulated)
    for (size_t i = 0; i < 10; ++i) {
        printf("Processing chunk %zu: %s\n", i, chunks[i].data);
        free(chunks[i].data); // Freeing allocated memory
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file_chunks(argv[1]);

    return EXIT_SUCCESS;
}
