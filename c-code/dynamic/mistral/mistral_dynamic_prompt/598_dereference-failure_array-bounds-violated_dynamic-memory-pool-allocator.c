#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    void* buffer;
    size_t size;
    size_t cap;
    size_t index;
} Pool;

Pool* create_pool(size_t size) {
    Pool* pool = malloc(sizeof(Pool));
    if (!pool) {
        fprintf(stderr, "Failed to allocate memory for the pool\n");
        exit(EXIT_FAILURE);
    }
    pool->buffer = malloc(size);
    if (!pool->buffer) {
        free(pool);
        fprintf(stderr, "Failed to allocate memory for the buffer\n");
        exit(EXIT_FAILURE);
    }
    pool->size = size;
    pool->cap = size;
    pool->index = 0;
    return pool;
}

void* alloc(Pool* pool, size_t size) {
    if (size > pool->size) {
        fprintf(stderr, "Requested size is greater than the pool's capacity\n");
        return NULL;
    }
    void* mem = pool->buffer + pool->index;
    pool->index += size;
    return mem;
}

void dealloc(Pool* pool, void* ptr) {
    if (ptr < pool->buffer || ptr >= pool->buffer + pool->size) {
        fprintf(stderr, "Invalid pointer provided for deallocation\n");
        return;
    }
    pool->index = (size_t)(ptr - pool->buffer);
}

int main() {
    Pool* pool = create_pool(1024);
    char* str = (char*)alloc(pool, 512);
    memset(str, 'X', 512);
    printf("Dereferencing invalid memory:\n");
    printf((char*)(str + pool->size),"\n"); // Dereference failure here
    dealloc(pool, str);
    free(pool);
    return 0;
}
