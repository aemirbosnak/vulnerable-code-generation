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

typedef struct MemPool {
    Block *pool;
    size_t capacity;
    size_t size;
} MemPool;

MemPool* create_mem_pool(size_t size) {
    MemPool *pool = (MemPool*)malloc(sizeof(MemPool));
    pool->capacity = 100;
    pool->size = size;
    pool->pool = (Block*)malloc(pool->capacity * sizeof(Block));

    for (size_t i = 0; i < pool->capacity; ++i) {
        pool->pool[i].size = size;
    }

    return pool;
}

void* allocate(MemPool *pool) {
    for (size_t i = 0; i < pool->capacity; ++i) {
        if (!pool->pool[i].size) {
            return &pool->pool[i].data;
        }
    }

    return NULL;
}

int main() {
    MemPool *mem_pool = create_mem_pool(42);
    char* buffer = (char*)allocate(mem_pool);
    printf("Allocated memory with size: %zu\n", mem_pool->pool[0].size);

    *buffer = 'A';
    printf("First char in allocated memory: %c\n", *buffer);

    free(mem_pool);
    return 0;
}
