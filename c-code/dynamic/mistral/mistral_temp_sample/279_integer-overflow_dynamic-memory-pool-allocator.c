#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POOL_SIZE 100000

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* pool = NULL;

Block* create_block(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) return NULL;
    new_block->size = size;
    new_block->next = pool;
    pool = new_block;
    return new_block;
}

void* alloc(size_t size) {
    if (size >= MAX_POOL_SIZE || pool == NULL) return NULL;

    Block* current = pool;
    while (current->next && current->next->size <= size) current = current->next;

    void* data = (void*)((char*)current + sizeof(Block) + current->size);
    current->size += size;

    return data;
}

void free_(void* ptr) {
    if (!ptr || !pool) return;

    Block* current = pool;
    while (current->next) current = current->next;

    current->size = sizeof(Block) + ((uintptr_t)ptr - ((uintptr_t)current + sizeof(Block)));
}

int main() {
    for (int i = 0; i < 10000; i++) create_block(4);
    char* buffer = (char*)alloc(100000);

    memset(buffer, 'A', 100000);
    printf("Buffer content: %c\n", buffer[5000]);

    free_(buffer);

    return 0;
}
