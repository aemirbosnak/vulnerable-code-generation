#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char pool[POOL_SIZE];
unsigned int free_index = 0;

void* allocate(unsigned int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

int main() {
    unsigned int large_size = POOL_SIZE * 2; // Integer overflow here
    void* ptr = allocate(large_size);
    if (ptr == NULL) {
        printf("Allocation failed\n");
    } else {
        printf("Allocation succeeded\n");
    }
    return 0;
}
