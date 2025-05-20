#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[0];
} Block;

typedef struct Pool {
    size_t capacity;
    Block* blocks;
    size_t first_free;
} Pool;

void init_pool(Pool* pool, size_t capacity) {
    pool->capacity = capacity;
    pool->blocks = malloc(capacity * sizeof(Block));
    pool->first_free = 0;
}

void allocate(Pool* pool, size_t size) {
    if (pool->first_free + size > pool->capacity) {
        printf("Error: No memory available\n");
        return;
    }

    Block* block = &pool->blocks[pool->first_free];
    block->size = size;
    pool->first_free += size;
}

void* acquire(Pool* pool, size_t size) {
    allocate(pool, size);
    return &pool->blocks[pool->first_free - size - sizeof(Block)];
}

int main() {
    Pool mem_pool;
    init_pool(&mem_pool, 1024);

    char* buffer = (char*)acquire(&mem_pool, 100);
    strcpy(buffer, "Secure data");

    char* vulnerable_read = (char*)acquire(&mem_pool, 1);
    printf("Vulnerable read: %c\n", *vulnerable_read); // OOB read vulnerability here

    return 0;
}
