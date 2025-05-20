#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_LENGTH 10
#define VALUE_LENGTH 20

typedef struct {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} CacheItem;

CacheItem cache[CACHE_SIZE];
int cacheIndex = 0;

void printCache() {
    printf("Cache:\n");
    for (int i = 0; i < cacheIndex; ++i) {
        printf("%s -> %s\n", cache[i].key, cache[i].value);
    }
}

void addItem(char *key, char *value) {
    if (cacheIndex >= CACHE_SIZE) {
        printf("Cache is full. Evicting an item...\n");
        evictItem();
    }

    strcpy(cache[cacheIndex].key, key);
    strcpy(cache[cacheIndex].value, value);
    ++cacheIndex;
}

void evictItem() {
    printf("Evicting item with key '%s' (randomly selected)\n", cache[0].key);
    memset(cache[0].key, 0, KEY_LENGTH);
    memset(cache[0].value, 0, VALUE_LENGTH);
}

int main() {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];

    for (int i = 0; i < 15; ++i) {
        sprintf(key, "key%d", i);
        sprintf(value, "value%d", i);

        addItem(key, value);
        printCache();

        if (i >= CACHE_SIZE) {
            sprintf(key, "key%d", (i - CACHE_SIZE) % CACHE_SIZE);
            printf("Reading out of bounds: %s\n", cache[i].key);
        }
    }

    return 0;
}
