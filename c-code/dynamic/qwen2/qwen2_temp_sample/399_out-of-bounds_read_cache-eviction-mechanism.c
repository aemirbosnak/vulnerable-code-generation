#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int data[CACHE_SIZE];
} Cache;

Cache cache = {{0}};

void evict_cache_entry(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        printf("Evicting cache entry %d\n", index);
        cache.data[index] = -1;
    } else {
        printf("Out of bounds access attempt: %d\n", index);
    }
}

int main() {
    for (int i = 0; i <= CACHE_SIZE; i++) {
        evict_cache_entry(i);
    }
    return 0;
}
