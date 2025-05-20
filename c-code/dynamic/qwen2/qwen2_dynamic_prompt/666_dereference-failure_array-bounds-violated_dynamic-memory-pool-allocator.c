#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
    int free_index;
} MemoryPool;

MemoryPool pool;

void init_pool() {
    pool.free_index = 0;
}

void* allocate(int size) {
    if (pool.free_index + size > POOL_SIZE) {
        return NULL; // Simulate allocation failure
    }
    void* ptr = &pool.data[pool.free_index];
    pool.free_index += size;
    return ptr;
}

int main() {
    init_pool();

    int* arr = (int*)allocate(10 * sizeof(int));
    if (arr == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }

    // Dereference failure: accessing out-of-bounds index
    int value = arr[10]; // This will cause an array bounds violation

    printf("Value: %d\n", value);

    return 0;
}
