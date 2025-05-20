#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int data;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

void cache_evict(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache[index].data = -1; // Evict the entry by setting data to -1
    } else {
        printf("Out of bounds write detected!\n");
        exit(1);
    }
}

int main() {
    int i;

    // Fill the cache with some values
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    // Print the initial cache state
    printf("Initial cache:\n");
    for (i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    // Intentionally try to evict an out-of-bounds index
    cache_evict(CACHE_SIZE); // This should trigger the out-of-bounds write detection

    return 0;
}
