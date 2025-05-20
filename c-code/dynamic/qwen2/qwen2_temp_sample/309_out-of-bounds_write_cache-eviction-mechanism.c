#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int data[CACHE_SIZE];
} Cache;

void evict_from_cache(Cache *cache, int index) {
    if (index < 0 || index >= CACHE_SIZE) {
        printf("Cache index out of bounds\n");
    } else {
        cache->data[index] = -1; // Simulate evicting an item by setting to -1
    }
}

int main() {
    Cache my_cache;
    for (int i = 0; i < CACHE_SIZE; i++) {
        my_cache.data[i] = i * 10;
    }

    printf("Initial cache contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("%d ", my_cache.data[i]);
    }
    printf("\n");

    // Deliberate out-of-bounds write vulnerability
    evict_from_cache(&my_cache, 12); // This will cause an out-of-bounds write

    printf("Modified cache contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("%d ", my_cache.data[i]);
    }
    printf("\n");

    return 0;
}
