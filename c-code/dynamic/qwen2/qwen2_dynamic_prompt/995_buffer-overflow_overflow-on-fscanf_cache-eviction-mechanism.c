#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int key;
    char value[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

int hash(int key) {
    return key % CACHE_SIZE;
}

void insert(int key, const char* value) {
    int index = hash(key);
    while (cache[index].key != -1) {
        if (cache[index].key == key) {
            // Update existing entry
            snprintf(cache[index].value, sizeof(cache[index].value), "%s", value);
            return;
        }
        index = (index + 1) % CACHE_SIZE;
    }
    cache[index].key = key;
    snprintf(cache[index].value, sizeof(cache[index].value), "%s", value);
}

void display_cache() {
    printf("Cache Contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            printf("Key: %d, Value: %s\n", cache[i].key, cache[i].value);
        }
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;
    }

    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int key;
    char value[300]; // Buffer larger than expected to trigger overflow

    while (fscanf(file, "%d %s", &key, value) != EOF) {
        insert(key, value);
    }

    fclose(file);

    display_cache();

    return EXIT_SUCCESS;
}
