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
    insert_into_cache(4, 40);
    insert_into_cache(5, 50);

    access_cache(3);
    access_cache(6); // This should cause an invalid pointer access

    return 0;
}
