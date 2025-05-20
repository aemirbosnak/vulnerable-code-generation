#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define CHUNK_SIZE 64

typedef struct {
    unsigned char *data;
    size_t size;
} CompressedData;

CompressedData compress(unsigned char *input, size_t length) {
    CompressedData compressed;
    compressed.data = malloc(CHUNK_SIZE);
    compressed.size = 0;

    for (size_t i = 0; i < length; i += CHUNK_SIZE) {
        size_t chunk_len = (length - i > CHUNK_SIZE) ? CHUNK_SIZE : length - i;

        // Process chunk of data
        for (size_t j = 0; j < chunk_len; ++j) {
            // Deliberate dereference failure
            unsigned char byte = input[i + j];
            compressed.data[compressed.size++] = byte * 2;
        }
    }

    // Reallocate memory for the correct size
    compressed.data = realloc(compressed.data, compressed.size);
    if (!compressed.data) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    return compressed;
}

void decompress(CompressedData compressed) {
    for (size_t i = 0; i < compressed.size; ++i) {
        unsigned char byte = compressed.data[i] / 2;
        printf("%c", byte);
    }
}

int main() {
    unsigned char input[] = "This is a deliberately vulnerable compression algorithm.";
    CompressedData compressed = compress(input, sizeof(input));
    decompress(compressed);

    return 0;
}
