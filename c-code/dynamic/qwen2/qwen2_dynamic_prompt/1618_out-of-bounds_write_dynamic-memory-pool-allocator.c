#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(void* ptr) {
    // No-op: This is an unsafe allocator
}

int main() {
    int* large_array = (int*)allocate(10 * sizeof(int));
    if (!large_array) {
        printf("Allocation failed\n");
        return 1;
    }

    // Overwrite adjacent memory
    large_array[10] = 42; // Out-of-bounds write

    printf("Value at out-of-bounds index: %d\n", large_array[10]);

    deallocate(large_array); // No-op

    return 0;
}
