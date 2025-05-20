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
        printf("Evicted entry: key=%d, value=%d\n", cache[cache_count].key, cache[cache_count].value);
    }
}

void add_to_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        evict_cache();
    }
    cache[cache_count].key = key;
    cache[cache_count].value = value;
    cache_count++;
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    add_to_cache(3, 30);
    add_to_cache(4, 40);
    add_to_cache(5, 50);

    // Intentional out-of-bounds write vulnerability
    cache[cache_count] = (CacheEntry){6, 60}; // This will overwrite the next memory location

    return 0;
}
