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

void print_cache(CacheEntry cache[]) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        printf("Key: %s, Value: %s\n", cache[i].key, cache[i].value);
    }
}

void insert_entry(CacheEntry *cache, const char *key, const char *value) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (!cache[i].key[0]) {
            strcpy(cache[i].key, key);
            strcpy(cache[i].value, value);
            return;
        }
    }

    // Overflow: Access cache[CACHE_SIZE] which is out of bounds.
    strcpy((char *)&cache[CACHE_SIZE], key);
}

int main() {
    CacheEntry cache[CACHE_SIZE];

    insert_entry(cache, "key1", "value1");
    insert_entry(cache, "key2", "value2");
    insert_entry(cache, "key3", "value3");

    print_cache(cache);

    return 0;
}
