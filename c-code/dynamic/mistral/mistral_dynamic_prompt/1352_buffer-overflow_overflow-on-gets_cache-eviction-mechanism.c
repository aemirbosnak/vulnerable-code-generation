#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_LENGTH 10
#define VALUE_LENGTH 100

typedef struct {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cacheIndex = 0;

void printCache() {
    for (int i = 0; i < cacheIndex; ++i) {
        printf("Key: %s, Value: %s\n", cache[i].key, cache[i].value);
    }
}

void addToCache(char *key, char *value) {
    if (cacheIndex >= CACHE_SIZE) {
        printf("Cache is full.\n");
        return;
    }
    strcpy(cache[cacheIndex].key, key);
    strcpy(cache[cacheIndex].value, value);
    ++cacheIndex;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    char buffer[100];
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];

    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%s %s", key, value);
        addToCache(key, value);
        // Intentionally not checking if buffer is too large, causing buffer overflow
        // DO NOT DO THIS IN REAL WORLD APPLICATIONS!
        addToCache(buffer, buffer);
    }

    printCache();

    return 0;
}
