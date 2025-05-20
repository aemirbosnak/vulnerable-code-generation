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
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].data = rand();
    }
}

void access_memory(int index) {
    if (index >= 0 && index < CACHE_SIZE) {
        printf("Accessing memory at index %d\n", index);
        cache[index].data++;
    } else {
        printf("Memory access out of bounds!\n");
    }
}

int main() {
    srand(time(NULL));

    // Simulate some cache accesses
    for (int i = 0; i < 20; i++) {
        access_memory(i);
    }

    // Evict cache entries
    evict_cache();

    // Intentionally access an out-of-bounds index to cause a dereference failure
    access_memory(CACHE_SIZE);

    return 0;
}
