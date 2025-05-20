#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data;
} PoolBlock;

PoolBlock *pool = NULL;
int pool_index = 0;

void init_pool() {
    pool = (PoolBlock *)malloc(POOL_SIZE * sizeof(PoolBlock));
    if (!pool) {
        fprintf(stderr, "Failed to allocate memory for pool\n");
        exit(EXIT_FAILURE);
    }
}

PoolBlock *allocate_block() {
    if (pool_index >= POOL_SIZE) {
        fprintf(stderr, "Memory pool is full\n");
        return NULL;
    }
    return &pool[pool_index++];
}

void free_pool() {
    free(pool);
}

int main() {
    init_pool();

    PoolBlock *block = allocate_block();
    if (block) {
        block->data = 42;
        printf("Allocated block with data: %d\n", block->data);
    }

    // Deliberate dereference failure (null pointer)
    PoolBlock *null_block = NULL;
    null_block->data = 99; // This will cause a segmentation fault

    free_pool();
    return 0;
}
