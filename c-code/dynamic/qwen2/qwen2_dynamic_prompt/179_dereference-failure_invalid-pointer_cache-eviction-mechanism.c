#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int key;
    int value;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_count = 0;

void evict_cache() {
    if (cache_count > 0) {
        cache_count--;
        printf("Evicted entry: %d\n", cache[cache_count].key);
    } else {
        printf("Cache is empty.\n");
    }
}

void access_memory(int *ptr) {
    if (ptr == NULL) {
        printf("Invalid pointer encountered!\n");
        exit(1);
    }
    printf("Accessing memory at address: %p\n", ptr);
    *ptr = 42; // Simulate accessing memory
}

void simulate_cache_eviction() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = i;
        cache[i].value = i * 10;
        cache_count++;
    }

    printf("Initial cache state:\n");
    for (int i = 0; i < cache_count; i++) {
        printf("Key: %d, Value: %d\n", cache[i].key, cache[i].value);
    }

    evict_cache();
    evict_cache();

    // Deliberate invalid pointer dereference
    int *invalid_ptr = NULL;
    access_memory(invalid_ptr);

    printf("Final cache state:\n");
    for (int i = 0; i < cache_count; i++) {
        printf("Key: %d, Value: %d\n", cache[i].key, cache[i].value);
    }
}

int main() {
    simulate_cache_eviction();
    return 0;
}
