#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* pool = NULL;
size_t pool_size = 0;

void add_to_pool(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) return;

    new_block->size = size;
    new_block->next = pool;
    pool = new_block;
    pool_size += size;
}

void* get_from_pool(size_t size) {
    if (pool_size == 0 || pool->size < size) return NULL;

    Block* current = pool;
    while (current->next && current->next->size < size) current = current->next;

    Block* to_return = current->next;
    current->next = current->next->next;
    pool_size -= to_return->size;
    return to_return->data;
}

int main() {
    add_to_pool(100);
    char* vulnerable_pointer = (char*) get_from_pool(50);

    strcpy(vulnerable_pointer, "Some data"); // Uses more than 50 bytes
    printf("%s\n", vulnerable_pointer);

    return 0;
}
