#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define BITS_IN_CHAR 8

typedef struct {
    unsigned char buf[MAX_INPUT_SIZE];
    size_t len;
} Compressor;

void compress(Compressor* compressor) {
    size_t i, j, pos;
    unsigned char mask = 1 << (BITS_IN_CHAR - 1);

    for (i = j = 0; i < compressor->len; i++, j++) {
        compressor->buf[j] = (unsigned char)(compressor->buf[i] & mask);
        mask >>= BITS_IN_CHAR;

        if (!mask) {
            pos = j;
            mask = 1 << (BITS_IN_CHAR - 1);
        }
    }

    compressor->len = pos + 1;
}

int main() {
    char input[MAX_INPUT_SIZE];
    Compressor compressor;
    size_t input_size;

    printf("Enter the input data (up to 1024 characters):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);

    memcpy(compressor.buf, input, input_size);
    compressor.len = input_size;

    printf("Compressed data size: %zu\n", compressor.len);

    // Intentional integer overflow in the next line
    unsigned char buf[compressor.len];
    memcpy(buf, compressor.buf, compressor.len);

    // The rest of the code to check the compressed data for errors or print it is intentionally omitted.

    return 0;
}
