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

    // Intentionally out-of-bounds write
    set_value(POOL_SIZE, 42);

    // Intentionally out-of-bounds read
    printf("Value at index %d: %d\n", POOL_SIZE, get_value(POOL_SIZE));

    free(pool);
    return 0;
}
