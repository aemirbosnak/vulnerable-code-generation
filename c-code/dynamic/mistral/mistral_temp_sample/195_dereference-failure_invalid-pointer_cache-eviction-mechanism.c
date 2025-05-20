#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_LENGTH 10

typedef struct {
    char key[KEY_LENGTH];
    void* value;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
unsigned int cacheIndex = 0;

void lru_eviction() {
    unsigned int leastRecentlyUsedIndex = 0;
    unsigned int currentIndex;

    for (currentIndex = 1; currentIndex < cacheIndex; ++currentIndex) {
        if (strcmp(cache[leastRecentlyUsedIndex].key, cache[currentIndex].key) > 0) {
            leastRecentlyUsedIndex = currentIndex;
        }
    }

    free(cache[leastRecentlyUsedIndex].value);
}

void set(const char* key, void* value) {
    if (cacheIndex >= CACHE_SIZE) {
        lru_eviction();
    }

    strcpy(cache[cacheIndex].key, key);
    cache[cacheIndex].value = value;
    ++cacheIndex;
}

void* get(const char* key) {
    unsigned int index;

    for (index = 0; index < cacheIndex; ++index) {
        if (strcmp(cache[index].key, key) == 0) {
            return cache[index].value;
        }
    }

    return NULL;
}

int main() {
    set("key1", (void*)0xdeadbeef);
    set("key2", (void*)0xdeadbeef);
    set("key3", (void*)0xdeadbeef);
    set("key4", (void*)0xdeadbeef);
    set("key5", (void*)0xdeadbeef);

    printf("Retrieving non-existing key: %p\n", get("non_existing_key"));

    return 0;
}
