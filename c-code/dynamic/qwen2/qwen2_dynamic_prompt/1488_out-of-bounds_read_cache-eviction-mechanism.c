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

void evict_cache() {
    static int index = 0;
    index = (index + 1) % CACHE_SIZE;
}

int read_cache(int key) {
    if (key >= 0 && key < CACHE_SIZE) {
        return cache[key].data;
    } else {
        // Out-of-bounds read
        return cache[(key % CACHE_SIZE)].data;
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    printf("Initial cache values:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    evict_cache();
    evict_cache();

    printf("\nAfter two evictions:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    printf("\nReading out-of-bounds value (should access cache[2]):\n");
    int out_of_bounds_value = read_cache(10);
    printf("Out-of-bounds value: %d\n", out_of_bounds_value);

    return 0;
}
