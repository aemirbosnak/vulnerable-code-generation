#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Compressor {
    int bufferSize;
    char *buffer;
} Compressor;

Compressor createCompressor(int size) {
    Compressor c;
    c.bufferSize = size;
    c.buffer = (char *) malloc(c.bufferSize * sizeof(char));
    return c;
}

void readIntoBuffer(Compressor *c, char *input, int len) {
    memcpy(c->buffer, input, len);
}

void compress(Compressor *c) {
    // Pseudo-compression algorithm
    for (int i = 0; i < c->bufferSize - 1; ++i) {
        if (c->buffer[i] == c->buffer[i + 1]) {
            c->buffer[i] = c->buffer[i] + 32;
        }
    }
}

void printCompressed(Compressor *c) {
    for (int i = 0; i < c->bufferSize; ++i) {
        printf("%c", c->buffer[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input> <buffer_size>\n", argv[0]);
        return 1;
    }

    Compressor c = createCompressor(atoi(argv[2]));
    char *input = argv[1];
    readIntoBuffer(&c, input, strlen(input));
    compress(&c);
    printCompressed(&c);

    free(c.buffer);
    return 0;
}
