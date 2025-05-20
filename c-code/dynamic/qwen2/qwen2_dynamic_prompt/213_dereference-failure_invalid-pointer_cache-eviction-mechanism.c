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
        printf("Cache is empty, nothing to evict.\n");
    }
}

void insert_into_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
    printf("Inserted entry: %d -> %d\n", key, value);
}

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1; // Key not found
}

int main() {
    insert_into_cache(1, 100);
    insert_into_cache(2, 200);
    insert_into_cache(3, 300);

    printf("Value for key 2: %d\n", get_from_cache(2));

    // Deliberate invalid pointer dereference
    CacheEntry *entry = NULL;
    printf("Value for key 4: %d\n", entry->value); // This will cause a segmentation fault

    return 0;
}
