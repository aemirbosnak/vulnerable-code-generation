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

    // Deliberate out-of-bounds read vulnerability
    char byte = read_byte(large_array + 10); // Reading past the end of the allocated array

    printf("Read byte: %d\n", byte);

    free(large_array);
    return 0;
}
