#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int data[CACHE_SIZE];
} Cache;

void evict_cache(Cache *cache, int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache->data[index] = 0;
    } else {
        printf("Out of bounds read attempt at index %d\n", index);
        // Deliberate out of bounds read vulnerability
        int *ptr = &cache->data[0];
        ptr[index] = 0; // This will cause an out of bounds read
    }
}

int main() {
    Cache myCache;
    int i;

    // Initialize cache with some values
    for (i = 0; i < CACHE_SIZE; i++) {
        myCache.data[i] = i;
    }

    // Evict cache entry at index 1024
    evict_cache(&myCache, 1024);

    return 0;
}
