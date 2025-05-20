#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char *pool;
    size_t used;
} MemoryPool;

MemoryPool pool;

void init_pool() {
    pool.pool = (char *)malloc(POOL_SIZE);
    if (!pool.pool) {
        fprintf(stderr, "Failed to allocate memory pool\n");
        exit(EXIT_FAILURE);
    }
    pool.used = 0;
}

void *allocate(size_t size) {
    if (size > POOL_SIZE - pool.used) {
        return NULL; // Not enough space
    }
    void *ptr = pool.pool + pool.used;
    pool.used += size;
    return ptr;
}

int main() {
    init_pool();

    // Example of an integer overflow
    size_t large_size = 999999999999999999;
    void *ptr = allocate(large_size);
    if (ptr == NULL) {
        printf("Allocation failed due to integer overflow\n");
    } else {
        printf("Allocation succeeded with pointer: %p\n", ptr);
    }

    free(pool.pool);
    return 0;
}
