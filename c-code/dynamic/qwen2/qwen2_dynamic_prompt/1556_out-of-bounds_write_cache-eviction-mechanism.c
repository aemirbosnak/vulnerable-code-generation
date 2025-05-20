#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

int cache[CACHE_SIZE];
int next_index = 0;

void evict_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i] = -1;
    }
}

void access_memory(int address) {
    if (address >= 0 && address < 100) {
        int index = address % CACHE_SIZE;
        cache[index] = address;
        printf("Accessed: %d\n", address);
    } else {
        printf("Out of bounds access: %d\n", address);
    }
}

int main() {
    evict_cache();

    // Simulate memory accesses
    for (int i = 0; i < 20; i++) {
        access_memory(i);
    }

    // Intentionally write to an out-of-bounds index
    cache[10] = 999; // This should overwrite the next_index variable

    // Accessing the overwritten value
    printf("Overwritten next_index: %d\n", next_index);

    return 0;
}
