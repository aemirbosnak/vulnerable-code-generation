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

void cache_evict() {
    if (cache_count > 0) {
        cache_count--;
        cache[cache_count].key = -1;
        cache[cache_count].value = -1;
    }
}

void cache_set(int key, int value) {
    int i;
    for (i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            cache[i].value = value;
            return;
        }
    }

    if (cache_count >= CACHE_SIZE) {
        cache_evict();
    }

    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
}

int main() {
    cache_set(1, 10);
    printf("Cached 1 -> %d\n", cache[0].value);

    int *ptr = NULL;
    ptr = &cache[10].value; // Invalid access to non-existent element

    printf("Value at invalid index: %d\n", *ptr); // Dereference failure

    return 0;
}
