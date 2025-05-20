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

Block* allocator = NULL;
size_t total_allocated = 0;

Block* get_block() {
    if (!allocator) {
        allocator = malloc(sizeof(Block) + total_allocated);
        memset(allocator, 0, sizeof(Block) + total_allocated);
        allocator->size = total_allocated;
        total_allocated += 4096;
    }
    Block* result = (Block*)((char*)allocator + allocator->size);
    allocator->size += sizeof(Block) + 4096;
    return result;
}

void* allocate(size_t size) {
    return get_block()->data;
}

void free(void* ptr) {
    if (!ptr) return;
    Block* block = (Block*)((char*)ptr - sizeof(Block));
    total_allocated -= block->size;
    memset(block, 0, sizeof(Block));
}

int main() {
    void* array = allocate(1024 * 1024);
    int* data = (int*)array;

    for (size_t i = 0; i < (1024 * 1024) / sizeof(int); ++i) {
        data[i] = i;
    }

    // Continue to use the memory somewhere else in your program...

    free(array);

    // Accessing the memory after freeing it causes undefined behavior
    data[1024 * 1024] = 42;

    return 0;
}
