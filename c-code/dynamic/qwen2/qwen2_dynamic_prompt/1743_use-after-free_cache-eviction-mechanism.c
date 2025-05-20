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

CacheEntry *cache[CACHE_SIZE];
int cache_count = 0;

void evict_cache() {
    if (cache_count > 0) {
        cache_count--;
        free(cache[cache_count]);
        cache[cache_count] = NULL;
    }
}

void add_to_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    CacheEntry *entry = (CacheEntry *)malloc(sizeof(CacheEntry));
    entry->key = key;
    entry->value = value;
    cache[cache_count++] = entry;
}

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i]->key == key) {
            return cache[i]->value;
        }
    }
    return -1;
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    printf("Value for key 1: %d\n", get_from_cache(1));
    evict_cache();
    printf("Value for key 2: %d\n", get_from_cache(2)); // Use after free vulnerability
    return 0;
}
