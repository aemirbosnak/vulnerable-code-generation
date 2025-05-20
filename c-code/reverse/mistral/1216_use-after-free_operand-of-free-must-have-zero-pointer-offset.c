#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

Block* alloc(size_t size) {
    Block* block = malloc(sizeof(Block) + size);
    if (!block) return NULL;
    block->size = size;
    return block;
}

void free_block(Block* block) {
    free(block);
}

void use_after_free(Block* block) {
    free_block(block);
    printf("%c\n", block->data[0]);
}

int main() {
    Block* block = alloc(1);
    block->data[0] = 'A';
    use_after_free(block);
    return 0;
}
