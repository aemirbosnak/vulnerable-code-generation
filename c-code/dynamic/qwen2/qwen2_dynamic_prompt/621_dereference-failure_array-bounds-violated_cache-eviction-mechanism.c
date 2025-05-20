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

void simulate_accesses() {
    for (int i = 0; i < 20; i++) {
        access_data(i % CACHE_SIZE);
        evict_cache();
    }
}

int main() {
    simulate_accesses();
    return 0;
}
