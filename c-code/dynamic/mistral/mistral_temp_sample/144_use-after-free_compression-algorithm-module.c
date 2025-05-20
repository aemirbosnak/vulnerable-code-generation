#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Compressor {
    char *buffer;
    size_t capacity;
    size_t length;
} Compressor;

void compress(Compressor *compressor, const char *input) {
    if (compressor->length + strlen(input) + 1 > compressor->capacity) {
        compressor->buffer = realloc(compressor->buffer, compressor->capacity * 2);
        compressor->capacity *= 2;
    }

    strcat(compressor->buffer, input);
    compressor->length += strlen(input) + 1;
}

void decompress(Compressor *compressor, char *output, size_t size) {
    if (compressor->length > size) {
        printf("Output buffer too small.\n");
        return;
    }

    strncpy(output, compressor->buffer, compressor->length);
    output[compressor->length] = '\0';

    compressor->buffer = realloc(compressor->buffer, 0);
    compressor->capacity = 0;
    compressor->length = 0;
}

int main() {
    Compressor compressor;
    compressor.buffer = malloc(BUFFER_SIZE);
    compressor.capacity = BUFFER_SIZE;
    compressor.length = 0;

    char input[BUFFER_SIZE];
    while (fgets(input, BUFFER_SIZE, stdin)) {
        compress(&compressor, input);
    }

    char output[BUFFER_SIZE];
    decompress(&compressor, output, BUFFER_SIZE);

    printf("Compressed data:\n%s\n", compressor.buffer);
    free(compressor.buffer);

    return 0;
}
