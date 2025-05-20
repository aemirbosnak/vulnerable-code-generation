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

int main() {
    init_pool();

    Block *blocks[10];
    for (int i = 0; i < 10; i++) {
        blocks[i] = allocate_block();
        if (blocks[i]) {
            blocks[i]->data = i;
        } else {
            printf("Allocation failed\n");
            exit(1);
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("Block %d: Data = %d\n", i, blocks[i]->data);
    }

    // Freeing all blocks except one
    for (int i = 0; i < 9; i++) {
        free_block(blocks[i]);
    }

    // Use-after-free vulnerability
    printf("Use-after-free: Data = %d\n", blocks[9]->data);

    free(pool);
    return 0;
}
