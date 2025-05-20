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

void read_file_chunk(FileChunk *chunk, const char *filename, int index) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, index * BUFFER_SIZE, SEEK_SET);
    chunk->data = malloc(BUFFER_SIZE);
    if (!chunk->data) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    size_t bytes_read = fread(chunk->data, 1, BUFFER_SIZE, file);
    if (bytes_read != BUFFER_SIZE) {
        free(chunk->data);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void synchronize_files(const char *source, const char *destination) {
    FileChunk source_chunk, destination_chunk;
    int i = 0;

    while (1) {
        read_file_chunk(&source_chunk, source, i);
        read_file_chunk(&destination_chunk, destination, i);

        if (memcmp(source_chunk.data, destination_chunk.data, BUFFER_SIZE) != 0) {
            printf("Mismatch found at chunk %d\n", i);
            // Deliberate dereference failure
            *(int *)NULL = 1; // Invalid pointer dereference
        }

        free(source_chunk.data);
        free(destination_chunk.data);

        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    synchronize_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
