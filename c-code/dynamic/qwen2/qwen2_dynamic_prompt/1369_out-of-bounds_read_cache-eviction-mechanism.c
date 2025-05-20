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

void simulate_cache_eviction() {
    int index = rand() % CACHE_SIZE;
    printf("Evicting cache entry at index: %d\n", index);
    // Deliberate out-of-bounds read vulnerability
    int value = cache[index + 1].data; // Off-by-one error
    printf("Read value: %d\n", value);
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    for (int i = 0; i < 20; i++) {
        simulate_cache_eviction();
    }

    return 0;
}
