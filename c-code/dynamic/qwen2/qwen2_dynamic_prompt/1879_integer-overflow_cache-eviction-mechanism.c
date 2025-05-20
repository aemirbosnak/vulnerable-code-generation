#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int key;
    int value;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_count = 0;

void add_to_cache(int key, int value) {
    if (cache_count >= CACHE_SIZE) {
        // Intentional integer overflow to demonstrate vulnerability
        int index = (key + cache_count) / CACHE_SIZE; // Overflow here
        if (index >= CACHE_SIZE) {
            printf("Cache overflow detected!\n");
            return;
        }
        cache[index].key = key;
        cache[index].value = value;
    } else {
        cache[cache_count].key = key;
        cache[cache_count].value = value;
        cache_count++;
    }
}

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    return -1;
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    add_to_cache(CACHE_SIZE * 2, 30); // This should trigger the overflow

    printf("Value for key 1: %d\n", get_from_cache(1));
    printf("Value for key 2: %d\n", get_from_cache(2));
    printf("Value for key %d: %d\n", CACHE_SIZE * 2, get_from_cache(CACHE_SIZE * 2));

    return 0;
}
