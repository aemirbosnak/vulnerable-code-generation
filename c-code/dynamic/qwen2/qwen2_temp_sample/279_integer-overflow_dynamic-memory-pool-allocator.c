#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char memory_pool[POOL_SIZE];
int free_index = 0;

void* allocate_memory(int size) {
    if (size > POOL_SIZE - free_index) {
        return NULL;
    }
    void* ptr = &memory_pool[free_index];
    free_index += size;
    return ptr;
}

int main() {
    int* large_array = (int*)allocate_memory(POOL_SIZE);
    if (large_array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Create an integer overflow by allocating negative size
    int negative_size = -1;
    int* overflow_array = (int*)allocate_memory(negative_size);
    if (overflow_array != NULL) {
        printf("Integer overflow occurred!\n");
    } else {
        printf("Allocation after overflow failed as expected.\n");
    }

    return 0;
}
