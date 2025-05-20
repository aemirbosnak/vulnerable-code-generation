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
    if (bytes_read != BUFFER_SIZE && !feof(file)) {
        fprintf(stderr, "Error reading file\n");
        free(chunk->data);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void synchronize_files(const char *source, const char *destination) {
    FILE *dest_file = fopen(destination, "w+");
    if (!dest_file) {
        perror("Failed to open destination file");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    while (1) {
        FileChunk chunk;
        read_file_chunk(&chunk, source, index);

        fwrite(chunk.data, 1, strlen(chunk.data), dest_file);
        free(chunk.data);

        if (feof(stdin)) break; // Simulate end of file by reaching EOF on stdin
        index++;
    }

    fclose(dest_file);
}

int main() {
    synchronize_files("source.txt", "destination.txt");
    return 0;
}
