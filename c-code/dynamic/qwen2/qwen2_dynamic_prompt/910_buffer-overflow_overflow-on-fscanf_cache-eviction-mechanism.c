#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int key;
    char data[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

void load_cache() {
    FILE *file = fopen("cache_data.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    for (int i = 0; i < CACHE_SIZE; i++) {
        if (fscanf(file, "%d %s", &cache[i].key, cache[i].data) != 2) {
            break;
        }
    }

    fclose(file);
}

void print_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("%d: %s\n", cache[i].key, cache[i].data);
    }
}

int main() {
    load_cache();
    print_cache();

    return 0;
}
