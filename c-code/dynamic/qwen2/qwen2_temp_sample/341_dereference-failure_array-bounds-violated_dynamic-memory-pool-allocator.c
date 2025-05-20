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
char* free_pointer = pool.data;

void init_pool() {
    free_pointer = pool.data;
}

char* allocate(size_t size) {
    if ((free_pointer - pool.data + size) > POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    char* ptr = free_pointer;
    free_pointer += size;
    return ptr;
}

int main() {
    init_pool();

    int num_elements = 100;
    int* array = (int*)allocate(num_elements * sizeof(int));

    // Simulate usage of allocated memory
    for (int i = 0; i < num_elements; i++) {
        array[i] = i;
    }

    // Dereference out-of-bounds index
    printf("%d\n", array[num_elements]);  // Violates array bounds

    return 0;
}
