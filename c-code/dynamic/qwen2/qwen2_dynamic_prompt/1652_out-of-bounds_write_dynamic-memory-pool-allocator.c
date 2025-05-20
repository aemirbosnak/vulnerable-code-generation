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

void deallocate(void* ptr) {}

int main() {
    int* large_array = (int*)allocate(10 * sizeof(int));
    if (!large_array) {
        printf("Allocation failed\n");
        return 1;
    }

    // Out-of-bounds write
    large_array[10] = 42; // This should overwrite adjacent memory

    printf("Value at large_array[10]: %d\n", large_array[10]);

    deallocate(large_array);
    return 0;
}
