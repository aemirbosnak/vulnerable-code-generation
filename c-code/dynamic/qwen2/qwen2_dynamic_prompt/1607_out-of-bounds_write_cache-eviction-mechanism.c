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
        // Deliberate out-of-bounds write vulnerability
        cache->data[index] = 1; // This will overwrite adjacent memory
    }
}

int main() {
    Cache myCache;
    int i;

    // Initialize cache with some values
    for (i = 0; i < CACHE_SIZE; i++) {
        myCache.data[i] = i;
    }

    // Intentionally evict cache at an out-of-bounds index
    evict_cache(&myCache, CACHE_SIZE + 1);

    // Print cache to show the effect of the out-of-bounds write
    printf("Cache after eviction:\n");
    for (i = 0; i < CACHE_SIZE; i++) {
        printf("%d ", myCache.data[i]);
    }
    printf("\n");

    return 0;
}
