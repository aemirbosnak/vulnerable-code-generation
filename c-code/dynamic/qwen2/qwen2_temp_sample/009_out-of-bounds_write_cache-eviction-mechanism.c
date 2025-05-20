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

void evict_cache(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache[index].data = -1; // Normal eviction
    } else {
        cache[0].data = 42; // Out-of-bounds write vulnerability
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    printf("Initial cache:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    evict_cache(CACHE_SIZE); // This should trigger the out-of-bounds write
    evict_cache(-1);      // This should also trigger the out-of-bounds write

    printf("\nAfter eviction:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    return 0;
}
