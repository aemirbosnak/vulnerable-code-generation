#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    void* data;
    size_t size;
    struct Block* next;
} Block;

Block* head = NULL;

Block* allocate(size_t size) {
    Block* newBlock = (Block*) malloc(sizeof(Block));
    if (!newBlock) return NULL;

    newBlock->data = malloc(size);
    if (!newBlock->data) {
        free(newBlock);
        return NULL;
    }

    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;

    return newBlock;
}

void deallocate(Block* block) {
    if (!block) return;

    free(block->data);
    free(block);
}

void print_memory_pool() {
    Block* current = head;
    printf("Memory Pool:\n");
    while (current) {
        printf("Block size: %ld, Address: %p\n", current->size, current->data);
        current = current->next;
    }
}

int main() {
    Block* blockA = allocate(10);
    Block* blockB = allocate(20);
    Block* blockC = allocate(30);

    void* invalid_ptr = ((char*)blockA->data) + blockA->size + 10;
    *((int*)invalid_ptr) = 42; // Dereference failure example

    print_memory_pool();

    deallocate(blockA);
    deallocate(blockB);
    deallocate(blockC);

    return 0;
}
