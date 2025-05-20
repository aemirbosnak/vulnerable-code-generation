#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char pool[POOL_SIZE];
size_t free_index = 0;

void* allocate(size_t size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
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

    // Dereference out-of-bounds index to cause failure
    int value = arr[10]; // This will access beyond the allocated memory

    printf("Value: %d\n", value);

    return 0;
}
