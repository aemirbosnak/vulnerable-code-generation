#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int id;
} PoolBlock;

PoolBlock *memory_pool = NULL;
int pool_index = 0;

void init_memory_pool() {
    memory_pool = (PoolBlock *)malloc(POOL_SIZE * sizeof(PoolBlock));
    if (!memory_pool) {
        fprintf(stderr, "Failed to allocate memory for memory pool\n");
        exit(EXIT_FAILURE);
    }
}

PoolBlock *allocate_block() {
    if (pool_index >= POOL_SIZE) {
        fprintf(stderr, "Memory pool exhausted\n");
        return NULL;
    }
    return &memory_pool[pool_index++];
}

void free_memory() {
    free(memory_pool);
}

int main() {
    init_memory_pool();

    // Allocate blocks
    PoolBlock *block1 = allocate_block();
    block1->id = 1;

    PoolBlock *block2 = allocate_block();
    block2->id = 2;

    // Intentionally set a block pointer to NULL
    PoolBlock *block3 = NULL;

    // Dereference the null pointer to cause a failure
    printf("ID of block3: %d\n", block3->id); // This line will crash

    free_memory();

    return 0;
}
