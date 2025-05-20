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

    // Deliberate integer overflow to corrupt adjacent memory
    int overflow_size = POOL_SIZE - sizeof(large_array) - 1;
    large_array[overflow_size] = 1; // This should overwrite the next variable

    int *next_var = (int *)(large_array + overflow_size + 1);
    printf("Next variable: %d\n", *next_var); // Should print garbage due to overflow

    free(large_array);
    return 0;
}
