//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

typedef struct {
    uint8_t code;
    uint16_t length;
    uint8_t data[BUFFER_SIZE];
} block_t;

void compress(const char *input, char *output, size_t size) {
    block_t block;
    uint16_t index = 0;

    while (size > 0) {
        block.code = input[index];
        block.length = 1;
        block.data[0] = input[index];

        for (uint16_t i = 1; i < BUFFER_SIZE && i < size; i++) {
            if (input[index + i] == block.data[i - 1]) {
                block.length++;
                block.data[i] = input[index + i];
            } else {
                break;
            }
        }

        memcpy(output, &block, sizeof(block));
        output += sizeof(block);

        index += block.length;
        size -= block.length;
    }
}

void decompress(const char *input, char *output, size_t size) {
    block_t block;
    uint16_t index = 0;

    while (size > 0) {
        memcpy(&block, input, sizeof(block));
        input += sizeof(block);

        for (uint16_t i = 0; i < block.length; i++) {
            output[index + i] = block.data[i];
        }

        index += block.length;
        size -= block.length;
    }
}

int main() {
    char input[] = "Hello, World!";
    char output[BUFFER_SIZE];

    compress(input, output, strlen(input));

    printf("Compressed data: ");
    for (size_t i = 0; i < sizeof(output); i++) {
        printf("%x ", output[i]);
    }
    printf("\n");

    decompress(output, input, strlen(input));

    printf("Decompressed data: %s\n", input);

    return 0;
}