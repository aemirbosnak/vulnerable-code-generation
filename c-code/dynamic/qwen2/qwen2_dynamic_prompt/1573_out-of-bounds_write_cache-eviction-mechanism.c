#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int data;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

void evict_cache_entry(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        cache[index].data = -1; // Evict by setting to an invalid value
    } else {
        printf("Out of bounds write detected!\n");
        exit(1);
    }
}

int main() {
    int i;
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    // Intentionally causing an out of bounds write
    evict_cache_entry(CACHE_SIZE);

    return 0;
}
