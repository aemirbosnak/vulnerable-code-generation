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
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

PoolBlock *allocate_block() {
    if (pool_index >= POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    return &pool[pool_index++];
}

void free_pool() {
    free(pool);
}

int main() {
    init_pool();

    PoolBlock *block1 = allocate_block();
    block1->data = 42;

    printf("Data: %d\n", block1->data);

    // Deliberate invalid pointer dereference
    PoolBlock *block2 = &pool[POOL_SIZE]; // This is out of bounds
    printf("Invalid Data: %d\n", block2->data); // Dereferencing invalid pointer

    free_pool();
    return 0;
}
