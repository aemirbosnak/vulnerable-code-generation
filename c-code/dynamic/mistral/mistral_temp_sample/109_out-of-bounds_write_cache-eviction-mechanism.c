#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_LENGTH 16
#define VALUE_LENGTH 64

typedef struct CacheEntry {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cacheIndex = 0;

void print_cache() {
    printf("Cache:\n");
    for (int i = 0; i < CACHE_SIZE; ++i) {
        printf("Index %d: Key %s, Value %s\n", i, cache[i].key, cache[i].value);
    }
}

void add_to_cache(char* key, char* value) {
    if (cacheIndex >= CACHE_SIZE) {
        printf("Cache is full.\n");
        return;
    }

    strcpy(cache[cacheIndex].key, key);
    strcpy(cache[cacheIndex].value, value);
    cacheIndex++;
}

int main() {
    char* key = (char*) malloc(KEY_LENGTH * sizeof(char));
    char* value = (char*) malloc(VALUE_LENGTH * sizeof(char));

    printf("Enter key: ");
    fgets(key, KEY_LENGTH, stdin);

    printf("Enter value: ");
    fgets(value, VALUE_LENGTH, stdin);

    add_to_cache(key, value);

    print_cache();

    // Out of bounds write vulnerability
    strcpy(cache[CACHE_SIZE].key, "OOB_Write");

    return 0;
}
