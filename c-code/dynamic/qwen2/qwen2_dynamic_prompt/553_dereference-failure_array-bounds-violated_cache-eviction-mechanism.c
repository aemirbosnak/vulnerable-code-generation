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
int cache_index = 0;

void evict_cache() {
    if (cache_index >= CACHE_SIZE) {
        cache_index = 0;
    }
}

void access_data(int index) {
    if (index >= CACHE_SIZE || index < 0) {
        printf("Error: Array bounds violated\n");
        exit(1);
    }
    cache[index].data++;
}

int main() {
    for (int i = 0; i < CACHE_SIZE * 2; i++) {
        evict_cache();
        access_data(cache_index);
        cache[cache_index].data = rand() % 100;
        cache_index++;
    }

    return 0;
}
