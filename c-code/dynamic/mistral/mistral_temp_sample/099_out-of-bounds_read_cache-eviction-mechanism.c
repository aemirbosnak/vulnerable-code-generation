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
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cacheIndex = 0;

void printCache() {
    printf("Cache:\n");
    for (int i = 0; i < cacheIndex; ++i) {
        printf("%s: %s\n", cache[i].key, cache[i].value);
    }
}

void insert(char *key, char *value) {
    if (cacheIndex >= CACHE_SIZE) {
        printf("Cache is full. Evicting oldest entry.\n");
        memset(cache[0].key, 0, KEY_LENGTH);
        memset(cache[0].value, 0, VALUE_LENGTH);
    }

    strcpy(cache[cacheIndex].key, key);
    strcpy(cache[cacheIndex].value, value);
    ++cacheIndex;
}

int main() {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];

    while (1) {
        printf("Enter key: ");
        scanf("%s", key);

        printf("Enter value: ");
        scanf("%s", value);

        insert(key, value);
        printCache();

        // Out of bounds read vulnerability
        printf("Key length: %d\n", strlen(key) + 1);
        printf("Value at index %d: %c\n", strlen(key) + 1, value[strlen(key) + 1]);
    }

    return 0;
}
