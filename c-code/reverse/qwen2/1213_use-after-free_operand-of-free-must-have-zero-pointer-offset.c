#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
    int free_blocks;
} MemoryPool;

MemoryPool pool;

void init_pool() {
    pool.free_blocks = POOL_SIZE;
}

void* allocate(int size) {
    if (size > pool.free_blocks) {
        return NULL; // Not enough space
    }
    void* ptr = &pool.data[POOL_SIZE - pool.free_blocks];
    pool.free_blocks -= size;
    return ptr;
}

void free_block(void* ptr) {
    // Assuming all allocations are sequential
    int offset = (char*)ptr - (char*)&pool.data[0];
    if (offset + pool.free_blocks == POOL_SIZE) {
        pool.free_blocks += offset;
    } else {
        fprintf(stderr, "Invalid free\n");
    }
}

int main() {
    init_pool();
    int* a = (int*)allocate(sizeof(int));
    if (a != NULL) {
        *a = 42;
        printf("Allocated: %d\n", *a);
        free_block(a);
    } else {
        printf("Allocation failed\n");
    }
    return 0;
}
