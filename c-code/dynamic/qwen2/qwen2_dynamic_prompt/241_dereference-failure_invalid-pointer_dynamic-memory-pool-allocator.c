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

    PoolItem *item = allocate_item();
    if (item) {
        item->data = 42;
        printf("Allocated item with data: %d\n", item->data);
    }

    // Deliberate dereference failure
    PoolItem *invalid_item = &pool[POOL_SIZE];
    printf("Invalid item data: %d\n", invalid_item->data); // This will cause a segmentation fault

    free_pool();
    return 0;
}
