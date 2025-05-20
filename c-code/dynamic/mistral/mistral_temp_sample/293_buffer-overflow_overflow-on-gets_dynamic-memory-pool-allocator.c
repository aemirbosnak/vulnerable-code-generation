#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    void* buffer;
    size_t capacity;
    size_t size;
    struct Pool* next;
} Pool;

Pool* pool_create(size_t size) {
    Pool* new_pool = (Pool*)malloc(sizeof(Pool));
    new_pool->buffer = malloc(size);
    new_pool->capacity = size;
    new_pool->size = 0;
    new_pool->next = NULL;
    return new_pool;
}

void* pool_alloc(Pool* pool) {
    if (pool->size >= pool->capacity) return NULL;
    void* data = (void*)((char*)pool->buffer + pool->size);
    pool->size += sizeof(char)*1024; // Arbitrary size for buffer overflow
    return data;
}

void pool_free(Pool* pool) {
    free(pool->buffer);
    free(pool);
}

int main() {
    Pool* pool = pool_create(1024);
    char* buffer = (char*)pool_alloc(pool);
    gets(buffer); // Buffer overflow vulnerability
    printf("Allocated and overflowed buffer:\n");
    printf("%s\n", buffer);
    pool_free(pool);
    return 0;
}
