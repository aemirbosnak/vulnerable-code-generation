#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block* pool = NULL;

void init() {
    pool = malloc(sizeof(Block));
    pool->size = 0;
    pool->next = NULL;
}

Block* allocate(size_t size) {
    Block* newBlock = malloc(sizeof(Block) + size);
    if (!newBlock) return NULL;

    newBlock->size = size;
    newBlock->next = pool;
    pool = newBlock;
    return newBlock;
}

void freeBlock(Block* block) {
    if (block == pool) pool = block->next;
    else {
        Block* current = pool;
        while (current->next != block) current = current->next;
        current->next = block->next;
    }
    free(block);
}

void useAfterFree(Block* freedBlock) {
    freedBlock->size += 10; // Intentional use after free
    printf("Data after free: %s\n", (char*)freedBlock + freedBlock->size);
}

int main() {
    init();

    Block* blockA = allocate(10);
    Block* blockB = allocate(20);

    freeBlock(blockA);

    useAfterFree(blockA);

    free(blockB);

    return 0;
}
