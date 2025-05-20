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
int cache_size = 0;

void evict_entry() {
    if (cache_size > 0) {
        cache_size--;
        printf("Evicted entry: %d\n", cache[cache_size].key);
    }
}

void insert_or_replace(int key, int value) {
    int found = 0;
    for (int i = 0; i < cache_size; i++) {
        if (cache[i].key == key) {
            cache[i].value = value;
            found = 1;
            break;
        }
    }

    if (!found && cache_size < CACHE_SIZE) {
        cache[cache_size].key = key;
        cache[cache_size].value = value;
        cache_size++;
    } else if (!found) {
        evict_entry();
        insert_or_replace(key, value);
    }
}

void print_cache() {
    for (int i = 0; i < cache_size; i++) {
        printf("%d: %d\n", cache[i].key, cache[i].value);
    }
}

int main() {
    insert_or_replace(1, 10);
    insert_or_replace(2, 20);
    insert_or_replace(3, 30);
    insert_or_replace(4, 40);
    insert_or_replace(5, 50);

    // Intentional dereference failure
    CacheEntry *entry = &cache[cache_size]; // cache_size is 5, so this points to invalid memory
    entry->key = 6;
    entry->value = 60;

    print_cache();

    return 0;
}
