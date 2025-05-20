#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10

typedef struct {
    int key;
    char value[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_index = 0;

void evict_cache() {
    if (cache_index >= CACHE_SIZE) {
        cache_index = 0;
    }
}

void set_cache(int key, const char *value) {
    while (1) {
        evict_cache();
        if (cache[cache_index].key == -1) {
            break;
        }
    }
    cache[cache_index].key = key;
    strcpy(cache[cache_index].value, value);
    cache[cache_index].value[strlen(value)] = '\0';
    cache_index++;
}

char* get_cache(int key) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return NULL;
}

int main() {
    memset(cache, -1, sizeof(cache));
    set_cache(1, "Hello");
    printf("Cached: %s\n", get_cache(1));

    // Deliberate dereference failure (forgotten memory)
    char *ptr = NULL;
    *ptr = 'X'; // This will cause a segmentation fault

    return 0;
}
