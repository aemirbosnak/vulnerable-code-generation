#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

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
    // Simulate inserting values into cache
    for (int i = 0; i < CACHE_SIZE + 10; i++) {
        insert_into_cache(i, i * 10);
    }

    // Simulate retrieving values from cache
    for (int i = 0; i < CACHE_SIZE + 10; i++) {
        printf("Key: %d, Value: %d\n", i, get_from_cache(i));
    }

    return 0;
}
