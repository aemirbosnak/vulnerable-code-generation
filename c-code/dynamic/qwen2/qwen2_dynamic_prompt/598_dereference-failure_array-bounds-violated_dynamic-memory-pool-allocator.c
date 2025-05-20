#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
} MemoryPool;

MemoryPool pool;
int next_free = 0;

void* allocate(int size) {
    if (next_free + size > POOL_SIZE) return NULL;
    void* ptr = &pool.data[next_free];
    next_free += size;
    return ptr;
}

void free_all() {
    next_free = 0;
}

int main() {
    int* arr = (int*)allocate(10 * sizeof(int));
    if (!arr) {
        printf("Allocation failed\n");
        return 1;
    }

    // Fill array with values
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }

    // Dereference out-of-bounds element to cause failure
    int value = ((int*)arr)[10]; // This will violate array bounds

    printf("Value: %d\n", value);

    free_all();
    return 0;
}
