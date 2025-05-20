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

typedef struct Pool {
    Block* start;
    Block* end;
} Pool;

Pool* create_pool(size_t size) {
    Pool* pool = (Pool*) malloc(sizeof(Pool));
    pool->start = (Block*) malloc(size);
    pool->end = (Block*) ((char*) pool->start + size);
    return pool;
}

void* allocate(Pool* pool, size_t size) {
    if (pool->start + size > pool->end)
        return NULL;

    Block* block = pool->start;
    block->size = size;
    pool->start += size;
    return (void*) block;
}

void deallocate(Pool* pool, void* ptr) {
    Block* block = (Block*) ptr;
    pool->start = (Block*) ((char*) pool->start - block->size);
}

int main() {
    Pool* pool = create_pool(1024);

    char* buffer = (char*) allocate(pool, 1025);
    strcpy(buffer, "This is a dynamic memory pool allocator example with integer overflow.");

    // Overflow the buffer
    strcat(buffer, "This will cause a segmentation fault due to the integer overflow.");

    // Deallocate the buffer
    deallocate(pool, buffer);

    // Access out-of-bounds memory
    printf("%c\n", *(buffer + 1024));

    return 0;
}
