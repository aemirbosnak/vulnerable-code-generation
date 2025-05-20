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
    }
}

int get(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1;
}

void set(int key, int value) {
    if (get(key) != -1) {
        // Key already exists, update its value
        for (int i = 0; i < cache_count; i++) {
            if (cache[i].key == key) {
                cache[i].value = value;
                return;
            }
        }
    } else {
        // Key does not exist, add it to the cache
        if (cache_count >= CACHE_SIZE) {
            evict_cache();
        }
        cache[cache_count].key = key;
        cache[cache_count].value = value;
        cache_count++;
    }
}

int main() {
    set(1, 10);
    set(2, 20);
    printf("Value of key 1: %d\n", get(1));
    printf("Value of key 2: %d\n", get(2));
    set(3, 30);
    printf("Value of key 1 after setting key 3: %d\n", get(1));
    printf("Value of key 2 after setting key 3: %d\n", get(2));
    printf("Value of key 3: %d\n", get(3));
    return 0;
}
