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
    if (next_free + size > POOL_SIZE) {
        return NULL; // Out of memory
    }
    void* ptr = &pool.data[next_free];
    next_free += size;
    return ptr;
}

char read_byte(void* ptr) {
    return *(char*)ptr;
}

int main() {
    int* large_array = (int*)allocate(10 * sizeof(int));
    if (!large_array) {
        printf("Allocation failed\n");
        return 1;
    }

    // Fill the array with some values
    for (int i = 0; i < 10; i++) {
        large_array[i] = i * 10;
    }

    // Intentionally read out of bounds
    char value = read_byte(&large_array[10]);

    printf("Value: %d\n", value);

    free(large_array);
    return 0;
}
