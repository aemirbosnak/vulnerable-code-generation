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

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    // Intentional out-of-bounds read vulnerability
    return cache[cache_count].value; // This will always access the last element after eviction
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    add_to_cache(3, 30);

    printf("Value for key 2: %d\n", get_from_cache(2));
    printf("Value for key 4: %d\n", get_from_cache(4)); // This should trigger the out-of-bounds read

    return 0;
}
