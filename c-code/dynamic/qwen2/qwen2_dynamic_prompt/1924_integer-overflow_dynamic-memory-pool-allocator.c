#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(void* ptr, int size) {
    // No-op in this unsafe implementation
}

int main() {
    int* large_array = (int*)allocate(POOL_SIZE);
    if (large_array == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Integer overflow to reuse allocated memory
    int* overflow_ptr = (int*)((char*)large_array + POOL_SIZE - sizeof(int));
    *overflow_ptr = 1;

    // Use the overflowed memory
    printf("%d\n", *overflow_ptr);

    // Deallocate (no-op)
    deallocate(large_array, POOL_SIZE);

    return 0;
}
