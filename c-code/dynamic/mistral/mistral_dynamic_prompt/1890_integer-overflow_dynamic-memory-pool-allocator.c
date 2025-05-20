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

Block* pool = NULL;
size_t total_allocated = 0;
size_t allocated_blocks = 0;

void alloc_block(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    new_block->size = size;
    if (!pool) {
        pool = new_block;
    } else {
        Block* current = pool;
        while (current->size != 0) {
            current = current->size + current;
        }
        current->size = size;
        current = current + sizeof(Block) + size;
    }
    allocated_blocks++;
}

void* get_memory(size_t size) {
    void* result;
    Block* current = pool;
    while (current->size != size) {
        if (current->size == 0) {
            return NULL;
        }
        current = current->size + current;
    }
    result = (void*) ((char*) current + sizeof(Block));
    current->size = 0;
    total_allocated += size;
    return result;
}

int main() {
    alloc_block(10);
    alloc_block(50);
    char* buffer = (char*) get_memory(51);
    printf(" buffer: %p\n", buffer);

    memset(buffer, 'a', 51);

    char* extra = (char*) get_memory(200);
    printf(" extra: %p\n", extra);

    free(pool);
    pool = NULL;

    printf("Total allocated: %zu\n", total_allocated);
    printf("Allocated blocks: %zu\n", allocated_blocks);

    return 0;
}
