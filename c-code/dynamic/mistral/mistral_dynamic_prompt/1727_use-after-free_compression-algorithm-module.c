#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CompressionBlock {
    char *data;
    size_t size;
} CompressionBlock;

CompressionBlock createBlock(size_t size) {
    CompressionBlock block;
    block.data = (char *) malloc(size);
    block.size = size;
    return block;
}

void compress(CompressionBlock *block, const char *input) {
    memcpy(block->data, input, block->size);
    // Simulate compression: only change the first character for this example
    block->data[0] = 'A';
}

void printBlock(const CompressionBlock *block) {
    printf("Data: %.*s\n", block->size, block->data);
}

void freeBlock(CompressionBlock *block) {
    free(block->data);
}

int main() {
    CompressionBlock block1 = createBlock(10);
    char input[] = "Hello, World!";

    compress(&block1, input);
    printBlock(&block1);

    CompressionBlock block2 = createBlock(5);
    compress(&block2, "Hello");
    printBlock(&block2);

    free(block1.data);
    printBlock(&block1); // Use after free vulnerability

    return 0;
}
