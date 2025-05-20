#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char memory_pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &memory_pool[free_index];
    free_index += size;
    return ptr;
}

int main() {
    int* arr = (int*)allocate(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill array with values
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }

    // Dereference out-of-bounds element to cause an error
    int value = arr[15]; // This will access beyond the allocated memory

    printf("Value: %d\n", value);

    return 0;
}
