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

void add_to_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
    printf("Added to cache: %d -> %d\n", key, value);
}

void get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            printf("Retrieved from cache: %d -> %d\n", key, cache[i].value);
            return;
        }
    }
    printf("Key not found in cache.\n");
}

int main() {
    add_to_cache(1, 100);
    add_to_cache(2, 200);
    add_to_cache(3, 300);

    get_from_cache(2);

    // Deliberate null pointer dereference vulnerability
    CacheEntry* null_entry = NULL;
    printf("Value: %d\n", null_entry->value); // This will cause a segmentation fault

    return 0;
}
