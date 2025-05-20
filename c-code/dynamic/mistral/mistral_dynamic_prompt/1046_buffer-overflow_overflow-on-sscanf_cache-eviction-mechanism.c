#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 100000
#define CACHE_SIZE 10

typedef struct CacheEntry {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cacheIndex = 0;

void printCache() {
    for (int i = 0; i < cacheIndex; ++i) {
        printf("Key: %s, Value: %s\n", cache[i].key, cache[i].value);
    }
}

int findIndex(char* key) {
    for (int i = 0; i < cacheIndex; ++i) {
        if (strcmp(key, cache[i].key) == 0) {
            return i;
        }
    }
    return -1;
}

void updateCache(char* key, char* value) {
    int index = findIndex(key);
    if (index != -1) {
        strcpy(cache[index].value, value);
    } else {
        if (cacheIndex == CACHE_SIZE) {
            cacheIndex = 0;
        }
        strcpy(cache[cacheIndex].key, key);
        strcpy(cache[cacheIndex].value, value);
        ++cacheIndex;
    }
}

int main(int argc, char* argv[]) {
    char inputLine[1000];
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    int i = 0;

    while (sscanf(argv[i], "%s %s", key, value) > 0) {
        updateCache(key, value);
        printCache();
        ++i;
    }

    return 0;
}
