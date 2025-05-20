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
    }
}

void insert_into_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
}

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1;
}

int main() {
    insert_into_cache(1, 10);
    insert_into_cache(2, 20);
    insert_into_cache(3, 30);

    printf("Value for key 2: %d\n", get_from_cache(2));

    // Intentional dereference failure
    CacheEntry *entry = &cache[cache_count]; // This is out-of-bounds
    entry->key = 4;
    entry->value = 40;

    printf("Value for key 4: %d\n", get_from_cache(4)); // Undefined behavior

    return 0;
}
