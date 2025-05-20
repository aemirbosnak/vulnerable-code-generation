#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int data;
} CacheEntry;

CacheEntry *cache[CACHE_SIZE];
int cache_count = 0;

void add_to_cache(int value) {
    if (cache_count >= CACHE_SIZE) {
        // Evict the first entry
        free(cache[0]);
        memmove(cache, cache + 1, sizeof(CacheEntry *) * (CACHE_SIZE - 1));
        cache_count--;
    }
    CacheEntry *new_entry = malloc(sizeof(CacheEntry));
    new_entry->data = value;
    cache[cache_count++] = new_entry;
}

void print_cache() {
    printf("Cache contents:\n");
    for (int i = 0; i < cache_count; i++) {
        printf("%d ", cache[i]->data);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < 20; i++) {
        add_to_cache(i);
        print_cache();
    }

    // Use-after-free vulnerability
    printf("Accessing freed memory: %d\n", cache[0]->data);

    return 0;
}
