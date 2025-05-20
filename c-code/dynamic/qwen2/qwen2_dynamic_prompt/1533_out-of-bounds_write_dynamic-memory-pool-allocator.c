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

void free_all() {
    next_free = 0;
}

int main() {
    int* large_array = (int*)allocate(10 * sizeof(int));
    if (!large_array) {
        printf("Allocation failed\n");
        return 1;
    }

    // Intentional out-of-bounds write
    large_array[10] = 42; // This should cause an out-of-bounds write

    free_all();
    return 0;
}
