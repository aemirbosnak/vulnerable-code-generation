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

void free_item(PoolItem *item) {
    // Intentional dereference failure: forgetting to reset pool_index
    item->data = 0; // This line is supposed to free the item, but it doesn't
}

void print_pool() {
    for (int i = 0; i < pool_index; i++) {
        printf("Item %d: %d\n", i, pool[i].data);
    }
}

int main() {
    init_pool();

    PoolItem *item1 = allocate_item();
    if (item1) {
        item1->data = 42;
    }

    PoolItem *item2 = allocate_item();
    if (item2) {
        item2->data = 99;
    }

    free_item(item1); // This should free item1, but it doesn't due to the bug

    print_pool(); // This will show an incorrect state due to the forgotten memory

    free(pool);

    return 0;
}
