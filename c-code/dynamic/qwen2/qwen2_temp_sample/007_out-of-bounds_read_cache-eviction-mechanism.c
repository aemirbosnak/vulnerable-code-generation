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

void insert(int key, int value) {
    if (cache_size >= CACHE_SIZE) {
        // Evict the first entry to make space
        cache[0].key = -1;
        cache[0].value = -1;
        cache_size--;
    }
    cache[cache_size].key = key;
    cache[cache_size].value = value;
    cache_size++;
}

int get(int key) {
    for (int i = 0; i < cache_size; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1; // Key not found
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);

    printf("Value of key 2: %d\n", get(2)); // Correct access

    // Deliberate out-of-bounds read vulnerability
    printf("Value at index 10: %d\n", cache[10].value); // Out-of-bounds read

    return 0;
}
