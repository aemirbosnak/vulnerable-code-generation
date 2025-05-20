#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct Compressor {
    char* buffer;
    size_t size;
} Compressor;

Compressor* create_compressor() {
    Compressor* compressor = malloc(sizeof(Compressor));
    compressor->buffer = malloc(BUFFER_SIZE);
    compressor->size = 0;
    return compressor;
}

void compress(Compressor* compressor, const char* input) {
    size_t i = 0;
    for (; i < strlen(input); ++i) {
        compressor->buffer[compressor->size++] = input[i];
        if (compressor->size >= BUFFER_SIZE) {
            break;
        }
    }
    compressor->buffer[compressor->size] = 0;
}

void free_compressor(Compressor* compressor) {
    free(compressor->buffer);
    free(compressor);
}

int main() {
    Compressor* compressor = create_compressor();
    compress(compressor, "The quick brown fox jumps over the lazy dog.");
    printf("Compressed string: %s\n", compressor->buffer);

    // Intentional use-after-free
    free(compressor);

    return 0;
}
