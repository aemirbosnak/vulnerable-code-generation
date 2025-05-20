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

void print_cache() {
    for (int i = 0; i < cache_count; i++) {
        printf("Key: %d, Value: %d\n", cache[i].key, cache[i].value);
    }
}

int main() {
    add_to_cache(1, 100);
    add_to_cache(2, 200);
    add_to_cache(CACHE_SIZE - 1, 300);
    add_to_cache(CACHE_SIZE, 400); // This should trigger the overflow

    print_cache();

    return 0;
}
