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

void add_to_cache(int value) {
    cache[cache_index].data = value;
    evict_cache();
    cache_index++;
}

int main() {
    char input[256];
    while (1) {
        printf("Enter a number to add to cache: ");
        fgets(input, sizeof(input), stdin);
        int value = atoi(input);
        add_to_cache(value);
        printf("Current cache state:\n");
        for (int i = 0; i < CACHE_SIZE; i++) {
            printf("%d ", cache[i].data);
        }
        printf("\n");
    }
    return 0;
}
