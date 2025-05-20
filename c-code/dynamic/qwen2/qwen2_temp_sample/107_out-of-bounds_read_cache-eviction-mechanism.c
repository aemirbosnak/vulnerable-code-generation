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
        printf("Evicted entry with key: %d\n", cache[cache_count].key);
    }
}

void access_cache(int key) {
    int index = key % CACHE_SIZE;
    if (index >= CACHE_SIZE || index < 0) {
        printf("Out of bounds read attempt!\n");
        return;
    }
    if (cache[index].key == key) {
        printf("Hit: Key %d, Value %d\n", key, cache[index].value);
    } else {
        printf("Miss: Evicting old entry and adding new entry\n");
        evict_cache();
        cache[cache_count].key = key;
        cache[cache_count].value = rand() % 100; // Simulate random value
        cache_count++;
    }
}

int main() {
    srand(time(0));
    access_cache(3); // Hit
    access_cache(7); // Miss
    access_cache(20); // Out of bounds read attempt!
    return 0;
}
