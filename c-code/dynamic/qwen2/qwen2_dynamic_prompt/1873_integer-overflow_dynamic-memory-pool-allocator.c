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
    static int offset = 0;
    void* ptr = &pool.data[offset];
    offset += size;
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
    int overflow_value = 2147483647 + 1; // INT_MAX + 1
    printf("Overflow value: %d\n", overflow_value);

    return 0;
}
