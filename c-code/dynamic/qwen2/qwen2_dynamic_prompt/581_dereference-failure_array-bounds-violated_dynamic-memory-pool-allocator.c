#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int data[POOL_SIZE];
} MemoryPool;

MemoryPool *pool = NULL;

void init_pool() {
    pool = (MemoryPool *)malloc(sizeof(MemoryPool));
    if (!pool) {
        fprintf(stderr, "Failed to allocate memory pool\n");
        exit(1);
    }
}

int get_value(int index) {
    return pool->data[index];
}

void set_value(int index, int value) {
    pool->data[index] = value;
}

int main() {
    init_pool();

    // Intentionally out-of-bounds access
    int out_of_bounds_index = POOL_SIZE + 1;
    printf("Value at out-of-bounds index %d: %d\n", out_of_bounds_index, get_value(out_of_bounds_index));

    free(pool);

    return 0;
}
