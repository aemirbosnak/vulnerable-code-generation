#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data;
} PoolItem;

PoolItem *pool = NULL;
int pool_index = 0;

void init_pool() {
    pool = (PoolItem *)malloc(POOL_SIZE * sizeof(PoolItem));
    if (!pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

PoolItem *allocate_item() {
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

    PoolItem *item1 = allocate_item();
    if (item1) {
        item1->data = 42;
    }

    // Deliberate dereference failure: using an invalid pointer
    PoolItem *item2 = &pool[POOL_SIZE]; // This is out of bounds
    printf("Data at invalid pointer: %d\n", item2->data); // Dereferencing invalid pointer

    free_pool();
    return 0;
}
