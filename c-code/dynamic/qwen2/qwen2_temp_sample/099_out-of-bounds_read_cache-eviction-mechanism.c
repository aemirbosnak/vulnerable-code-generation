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
int cache_index = 0;

void evict_cache() {
    if (cache_index >= CACHE_SIZE) {
        cache_index = 0;
    }
}

int read_from_cache(int index) {
    return cache[index].data;
}

int main() {
    // Initialize cache with some values
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    // Simulate cache usage
    for (int i = 0; i < CACHE_SIZE + 2; i++) {
        evict_cache();
        int value = read_from_cache(cache_index);
        printf("Read from cache[%d]: %d\n", cache_index, value);
    }

    return 0;
}
