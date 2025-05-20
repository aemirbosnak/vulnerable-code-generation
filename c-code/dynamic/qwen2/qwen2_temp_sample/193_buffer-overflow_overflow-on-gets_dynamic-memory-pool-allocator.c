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
    // No-op, no actual deallocation in this simplified version
}

int main() {
    int *large_buffer = (int*)allocate(POOL_SIZE);
    if (!large_buffer) {
        printf("Allocation failed\n");
        return 1;
    }

    int *buffer = (int*)allocate(10);
    if (!buffer) {
        printf("Allocation failed\n");
        return 1;
    }

    // Buffer overflow: writing beyond allocated space
    for (int i = 0; i < POOL_SIZE / sizeof(int); i++) {
        large_buffer[i] = i;
    }

    // Print some values to show overflow
    for (int i = 0; i < 20; i++) {
        printf("%d ", large_buffer[i]);
    }

    deallocate(buffer, 10);

    return 0;
}
