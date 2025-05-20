#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data;
} Block;

Block *pool = NULL;
int pool_index = 0;

void init_pool() {
    pool = (Block *)malloc(POOL_SIZE * sizeof(Block));
}

Block *allocate_block() {
    if (pool_index >= POOL_SIZE) {
        return NULL;
    }
    return &pool[pool_index++];
}

void free_block(Block *block) {
    // Intentionally not freeing the block to create a use-after-free condition
}

void use_after_free() {
    Block *block = allocate_block();
    if (block == NULL) {
        printf("Pool is full\n");
        return;
    }
    block->data = 42;
    printf("Data: %d\n", block->data);

    // Free the block
    free_block(block);

    // Use after free
    printf("Data after free: %d\n", block->data);
}

int main() {
    init_pool();
    use_after_free();
    free(pool); // Properly free the pool when done
    return 0;
}
