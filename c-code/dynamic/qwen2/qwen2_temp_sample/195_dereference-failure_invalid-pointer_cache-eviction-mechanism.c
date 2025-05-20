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
int next_index = 0;

void evict_cache() {
    if (next_index >= CACHE_SIZE) {
        next_index = 0;
    }
}

void set_cache(int key, int value) {
    cache[next_index].key = key;
    cache[next_index].value = value;
    evict_cache();
}

int get_cache(int key) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1;
}

void print_cache() {
    printf("Cache: ");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("(%d, %d) ", cache[i].key, cache[i].value);
    }
    printf("\n");
}

int main() {
    set_cache(1, 10);
    set_cache(2, 20);
    set_cache(3, 30);
    print_cache();

    // Intentional invalid pointer access
    ((CacheEntry *)NULL)->key = 42;

    return 0;
}
