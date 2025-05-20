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
}

void *allocate_item() {
    if (pool_index >= POOL_SIZE) {
        return NULL;
    }
    return &pool[pool_index++];
}

void free_item(void *item) {
    // Simulate freeing an item by setting its index to -1
    int index = ((PoolItem *)item - pool);
    if (index >= 0 && index < POOL_SIZE) {
        pool[index].data = -1;
    }
}

void use_after_free() {
    PoolItem *item = allocate_item();
    if (item != NULL) {
        item->data = 42;
        printf("Allocated item with data: %d\n", item->data);
        free_item(item);
        printf("Freed item with data: %d\n", item->data); // Use after free
    } else {
        printf("Failed to allocate item.\n");
    }
}

int main() {
    init_pool();
    use_after_free();
    free(pool);
    return 0;
}
