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
char* free_ptr = pool.data;

void* allocate(size_t size) {
    if (free_ptr + size > pool.data + POOL_SIZE) {
        return NULL; // Out of memory
    }
    void* ptr = free_ptr;
    free_ptr += size;
    return ptr;
}

int main() {
    int* array = (int*)allocate(10 * sizeof(int));
    if (!array) {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    printf("%d\n", array[5]); // Valid access

    // Forgetting to free memory
    // int* forgotten_memory = (int*)allocate(sizeof(int));

    // Dereferencing forgotten memory
    // printf("%d\n", *forgotten_memory); // Dereference failure

    return 0;
}
