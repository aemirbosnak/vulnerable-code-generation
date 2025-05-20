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

void evict_cache_entry(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache[index].data = -1; // Normal eviction
    } else {
        printf("Out of bounds write detected!\n");
        cache[0].data = 42; // Deliberate out of bounds write
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    printf("Initial cache state:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    evict_cache_entry(CACHE_SIZE); // This should trigger the out of bounds write
    evict_cache_entry(-1);      // This should also trigger the out of bounds write

    printf("\nFinal cache state after eviction:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    return 0;
}
