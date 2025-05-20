#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} FileChunk;

void read_file_chunk(FileChunk *chunk) {
    chunk->size = rand() % (MAX_FILE_SIZE + 1);
    chunk->data = malloc(chunk->size);
    if (!chunk->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Simulate reading data from a file
    memset(chunk->data, 'A', chunk->size);
}

void process_file_chunks(FileChunk *chunks, int num_chunks) {
    size_t total_size = 0;
    for (int i = 0; i < num_chunks; i++) {
        total_size += chunks[i].size;
    }

    // Integer overflow vulnerability
    char *combined_data = malloc(total_size); // Vulnerable line
    if (!combined_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t offset = 0;
    for (int i = 0; i < num_chunks; i++) {
        memcpy(combined_data + offset, chunks[i].data, chunks[i].size);
        offset += chunks[i].size;
    }

    printf("Combined data size: %zu\n", total_size);
    free(combined_data);

    for (int i = 0; i < num_chunks; i++) {
        free(chunks[i].data);
    }
}

int main() {
    srand(time(NULL));
    int num_chunks = rand() % 10 + 1;
    FileChunk *chunks = malloc(num_chunks * sizeof(FileChunk));
    if (!chunks) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_chunks; i++) {
        read_file_chunk(&chunks[i]);
    }

    process_file_chunks(chunks, num_chunks);

    free(chunks);
    return EXIT_SUCCESS;
}
