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

void insert_into_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
    printf("Inserted entry: %d -> %d\n", key, value);
}

void access_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            printf("Accessed entry: %d -> %d\n", key, cache[i].value);
            return;
        }
    }
    printf("Key not found: %d\n", key);
}

int main() {
    insert_into_cache(1, 10);
    insert_into_cache(2, 20);
    insert_into_cache(3, 30);

    access_cache(2);
    access_cache(4); // Key not found

    // Deliberate invalid pointer dereference
    CacheEntry *entry = NULL;
    printf("Value at invalid pointer: %d\n", entry->value); // Dereference failure

    return 0;
}
