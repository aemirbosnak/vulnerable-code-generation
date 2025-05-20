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
        return NULL; // Allocation too large
    }
    void* ptr = pool.data + pool.size;
    pool.size += size;
    return ptr;
}

int main() {
    int *large_array = (int *)allocate(POOL_SIZE);
    if (!large_array) {
        printf("Allocation failed\n");
        return 1;
    }

    int num_elements = POOL_SIZE / sizeof(int);
    for (int i = 0; i < num_elements; i++) {
        large_array[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += large_array[i];
    }

    printf("Sum: %d\n", sum);

    // Integer overflow vulnerability
    int overflow_size = POOL_SIZE - 1;
    int *overflow_ptr = (int *)allocate(overflow_size);
    if (!overflow_ptr) {
        printf("Allocation failed\n");
        return 1;
    }

    overflow_ptr[0] = 1;
    overflow_ptr[1] = 2;

    printf("Overflow value: %d\n", overflow_ptr[0]);

    return 0;
}
