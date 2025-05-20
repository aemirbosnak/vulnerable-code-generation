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

CacheEntry cache[CACHE_SIZE];
int next_index = 0;

void evict_cache() {
    if (next_index >= CACHE_SIZE) {
        next_index = 0;
    }
}

void access_data(int index) {
    if (index < 0 || index >= CACHE_SIZE) {
        printf("Error: Array bounds violated\n");
        exit(1);
    }
    cache[index].data++;
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    // Simulate accessing data outside the cache bounds
    access_data(CACHE_SIZE);

    return 0;
}
