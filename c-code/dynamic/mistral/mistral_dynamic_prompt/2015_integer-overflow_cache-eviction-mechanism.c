#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_SIZE 10
#define VALUE_SIZE 10

typedef struct CacheEntry {
    int key;
    char value[VALUE_SIZE];
} CacheEntry;

typedef struct Cache {
    CacheEntry entries[CACHE_SIZE];
    int count;
} Cache;

void cache_init(Cache* cache) {
    cache->count = 0;
}

void cache_put(Cache* cache, int key, const char* value) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (!cache->entries[i].key) {
            cache->entries[i].key = key;
            strcpy(cache->entries[i].value, value);
            ++cache->count;
            return;
        }
        if (cache->entries[i].key == key) {
            strcpy(cache->entries[i].value, value);
            return;
        }
    }
    // Intentional integer overflow in this next line to demonstrate vulnerability
    cache->entries[(cache->count) % CACHE_SIZE].key = key;
}

int main(int argc, char* argv[]) {
    Cache cache;
    cache_init(&cache);

    // Fill the cache with data
    for (int i = 0; i < 11; ++i) {
        char buf[VALUE_SIZE];
        snprintf(buf, VALUE_SIZE, "entry_%d", i);
        cache_put(&cache, i, buf);
    }

    // Overflow will occur on the next cache insert
    char overflow_buf[VALUE_SIZE];
    snprintf(overflow_buf, VALUE_SIZE, "entry_%d", CACHE_SIZE + 1);
    cache_put(&cache, CACHE_SIZE + 1, overflow_buf);

    return 0;
}
