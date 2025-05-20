#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define CACHE_SIZE 10

typedef struct {
    int data[CACHE_SIZE];
} Cache;

void evictCache(Cache *cache, int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache->data[index] = -1;
    } else {
        printf("Out of bounds read attempt\n");
    }
}

int main() {
    Cache myCache;
    
    // Fill cache with initial values
    for (int i = 0; i < CACHE_SIZE; i++) {
        myCache.data[i] = i + 1;
    }

    // Simulate an out of bounds read
    evictCache(&myCache, CACHE_SIZE);

    return 0;
}
