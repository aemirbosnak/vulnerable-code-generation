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

void evict_cache() {
    static int index = 0;
    index = (index + 1) % CACHE_SIZE;
}

int read_cache(int key) {
    if (key >= 0 && key < CACHE_SIZE) {
        return cache[key].data;
    } else {
        // Out-of-bounds read
        return cache[-(key + 1)].data; // Exploiting out-of-bounds access
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = i * 10;
    }

    printf("Initial cache values:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }

    evict_cache();
    evict_cache();

    printf("\nReading from out-of-bounds index -3:\n");
    int value = read_cache(-3);
    printf("Value at cache[-3]: %d\n", value);

    return 0;
}
