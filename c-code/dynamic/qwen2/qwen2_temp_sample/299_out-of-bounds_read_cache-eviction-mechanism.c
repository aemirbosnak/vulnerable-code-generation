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

void addToCache(int key, int value) {
    if (key >= CACHE_SIZE || key < 0) {
        printf("Error: Out of bounds access\n");
        exit(1);
    }
    cache[key].data = value;
}

int getFromCache(int key) {
    if (key >= CACHE_SIZE || key < 0) {
        printf("Error: Out of bounds access\n");
        exit(1);
    }
    return cache[key].data;
}

void displayCache() {
    printf("Cache contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("cache[%d] = %d\n", i, cache[i].data);
    }
}

int main() {
    addToCache(2, 100);
    addToCache(3, 200);

    printf("Value from cache[2]: %d\n", getFromCache(2));
    printf("Value from cache[3]: %d\n", getFromCache(3));

    // Intentionally accessing an out-of-bounds index to demonstrate the vulnerability
    printf("Intentional out-of-bounds read: %d\n", getFromCache(CACHE_SIZE + 1));

    return 0;
}
