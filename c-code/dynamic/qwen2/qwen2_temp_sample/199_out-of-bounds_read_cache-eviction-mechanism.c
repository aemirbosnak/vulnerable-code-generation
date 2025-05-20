#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int data;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

void load_cache(int index, int value) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache[index].data = value;
    } else {
        printf("Out of bounds write detected!\n");
    }
}

int read_cache(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        return cache[index].data;
    } else {
        printf("Out of bounds read detected!\n");
        return -1; // Return an invalid value to indicate error
    }
}

int main() {
    // Initialize cache with some values
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    // Read from within the cache
    printf("Value at index 500: %d\n", read_cache(500));

    // Intentionally read from an out-of-bounds index
    printf("Value at index 1024: %d\n", read_cache(CACHE_SIZE));

    // Intentionally write to an out-of-bounds index
    load_cache(CACHE_SIZE, 999);

    return 0;
}
