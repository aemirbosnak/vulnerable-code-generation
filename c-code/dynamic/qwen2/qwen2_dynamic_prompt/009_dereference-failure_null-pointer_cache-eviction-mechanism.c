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
        entry_to_evict->key = -1; // Mark as invalid
        entry_to_evict->value = -1;
    } else {
        printf("Error: Attempted to evict from an empty cache.\n");
    }
}

void add_to_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }

    CacheEntry new_entry = {key, value};
    cache[cache_count++] = new_entry;
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    add_to_cache(3, 30);

    // Intentionally set cache_count to a negative value to trigger the null pointer dereference
    cache_count = -1;

    evict_cache();

    return 0;
}
