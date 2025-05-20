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
    if ((free_ptr - pool.data + size) > POOL_SIZE) {
        return NULL; // Out of memory
    }
    void* ptr = free_ptr;
    free_ptr += size;
    return ptr;
}

int main() {
    int* num = (int*)allocate(sizeof(int));
    *num = 42;

    printf("Value: %d\n", *num);

    // Dereference failure: using freed memory
    int* forgotten_num = (int*)allocate(sizeof(int));
    *forgotten_num = 99; // This should overwrite the previous value

    printf("Forgotten Value: %d\n", *num); // Undefined behavior

    return 0;
}
