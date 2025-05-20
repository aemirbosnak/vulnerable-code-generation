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
        cache->data[index] = -1;
    } else {
        printf("Out of bounds read attempt at index %d\n", index);
        // Deliberate out of bounds read vulnerability
        int value = cache->data[index]; // This line intentionally causes an out of bounds read
        printf("Read value: %d\n", value);
    }
}

int main() {
    Cache myCache;
    for (int i = 0; i < CACHE_SIZE; i++) {
        myCache.data[i] = i;
    }

    evict_cache(&myCache, 512); // Intentionally causing an out of bounds read
    evict_cache(&myCache, 1023); // Accessing last element
    evict_cache(&myCache, 1024); // Out of bounds access

    return 0;
}
