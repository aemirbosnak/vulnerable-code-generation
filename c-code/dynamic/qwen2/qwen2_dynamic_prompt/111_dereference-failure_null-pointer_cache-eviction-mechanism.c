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
    if (cache_count == 0) {
        printf("Cache is empty.\n");
        return;
    }

    // Simulate eviction policy: evict the first entry
    CacheEntry *entry_to_evict = &cache[0];

    // Deliberate null pointer dereference vulnerability
    if (entry_to_evict != NULL) {
        printf("Evicting entry with key %d and value %d\n", entry_to_evict->key, entry_to_evict->value);
        entry_to_evict = NULL; // Intentionally set to NULL to cause dereference failure
    } else {
        printf("Failed to evict entry due to null pointer.\n");
    }
}

int main() {
    // Initialize cache with some entries
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = i;
        cache[i].value = i * 10;
        cache_count++;
    }

    // Evict cache entries
    for (int i = 0; i < CACHE_SIZE + 1; i++) {
        evict_cache();
    }

    return 0;
}
