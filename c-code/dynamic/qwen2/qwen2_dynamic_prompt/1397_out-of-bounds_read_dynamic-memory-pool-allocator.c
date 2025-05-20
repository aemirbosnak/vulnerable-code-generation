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

void read_memory(void* ptr, int offset, int length) {
    char* data_ptr = (char*)ptr;
    for (int i = 0; i < length; i++) {
        printf("%d ", data_ptr[offset + i]);
    }
    printf("\n");
}

int main() {
    int* int_ptr = (int*)allocate(sizeof(int));
    *int_ptr = 42;

    // Deliberate out-of-bounds read vulnerability
    read_memory(int_ptr, -1, sizeof(int));

    return 0;
}
