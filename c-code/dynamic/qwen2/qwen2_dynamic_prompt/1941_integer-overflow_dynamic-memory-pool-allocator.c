#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    int size;
    char data[POOL_SIZE];
} MemoryPool;

MemoryPool pool;

void* allocate(int size) {
    if (size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool.data[pool.size];
    pool.size += size;
    return ptr;
}

int main() {
    int chunk_size = 100;
    int num_chunks = 10;

    // Allocate chunks to fill the pool
    for (int i = 0; i < num_chunks; i++) {
        allocate(chunk_size);
    }

    // Intentionally cause an integer overflow by allocating one more chunk
    allocate(1);

    printf("Allocation successful!\n");
    return 0;
}
