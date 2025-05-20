#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_POOL_SIZE 10000

typedef struct Pool {
    void* blocks[MAX_POOL_SIZE];
    size_t size;
} Pool;

Pool pool;
size_t idx = 0;

void* allocate(size_t size) {
    if (idx >= MAX_POOL_SIZE) {
        return NULL;
    }

    pool.blocks[idx] = malloc(size);
    if (!pool.blocks[idx]) {
        return NULL;
    }

    idx++;
    pool.size += size;
    return pool.blocks[idx - 1];
}

int main() {
    int* arr;
    int* ptr;

    arr = (int*)allocate(sizeof(int) * 100);
    if (!arr) {
        printf("Failed to allocate memory for array.\n");
        return 1;
    }

    ptr = (int*)allocate(sizeof(int));
    if (!ptr) {
        printf("Failed to allocate memory for single int.\n");
        return 1;
    }

    *ptr = 42;
    printf("Stored value: %d\n", *ptr);

    free(arr);
    free(ptr);

    return 0;
}
