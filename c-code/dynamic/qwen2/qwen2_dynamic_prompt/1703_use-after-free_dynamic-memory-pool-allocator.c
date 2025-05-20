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
    // Simulate freeing by setting to a known value
    block->data = -1;
}

void use_after_free() {
    Block *b = allocate_block();
    if (b == NULL) {
        printf("Allocation failed\n");
        return;
    }
    b->data = 42;
    printf("Data: %d\n", b->data);

    // Free the block
    free_block(b);

    // Use after free vulnerability
    printf("Data after free: %d\n", b->data);
}

int main() {
    init_pool();
    use_after_free();
    free(pool); // Clean up the pool
    return 0;
}
