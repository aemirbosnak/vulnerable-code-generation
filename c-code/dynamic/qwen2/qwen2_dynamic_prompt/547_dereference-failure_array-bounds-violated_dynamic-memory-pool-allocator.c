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

    // Deliberate out-of-bounds write
    set_value(POOL_SIZE, 42);

    // Deliberate out-of-bounds read
    int value = get_value(POOL_SIZE);

    printf("Value: %d\n", value);

    free(pool);
    return 0;
}
