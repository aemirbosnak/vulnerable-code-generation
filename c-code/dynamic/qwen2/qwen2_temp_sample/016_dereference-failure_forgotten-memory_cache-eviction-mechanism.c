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

void insert(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        // Evict the first entry in the cache
        cache[0].key = -1;
        cache[0].value = -1;
        cache_count--;
    }
    CacheEntry new_entry = {key, value};
    cache[cache_count] = new_entry;
    cache_count++;
}

int get(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1;
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);

    printf("Value for key 2: %d\n", get(2));

    // Deliberate dereference failure (forgotten memory)
    CacheEntry *entry = &cache[3]; // This is out of bounds
    printf("Value for key 4: %d\n", entry->value); // Dereferencing invalid memory

    return 0;
}
