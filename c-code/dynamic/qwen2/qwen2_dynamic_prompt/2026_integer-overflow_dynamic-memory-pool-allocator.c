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

void deallocate(void* ptr, int size) {
    // No-op in this unsafe implementation
}

int main() {
    int* large_array = (int*)allocate(POOL_SIZE / sizeof(int));
    if (large_array == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Integer overflow to reuse allocated memory
    int* overflowed_ptr = (int*)((char*)large_array - 1);
    *overflowed_ptr = 42; // This should overwrite adjacent memory

    printf("Value at overflowed pointer: %d\n", *overflowed_ptr);

    deallocate(large_array, POOL_SIZE / sizeof(int));

    return 0;
}
