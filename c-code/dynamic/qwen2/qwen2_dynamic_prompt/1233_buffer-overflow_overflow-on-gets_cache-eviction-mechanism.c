#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 1024

typedef struct {
    char data[CACHE_SIZE];
} CacheEntry;

CacheEntry cache[10];

void addToCache(const char *key, const char *value) {
    int index = hashFunction(key);
    if (strlen(value) >= sizeof(cache[index].data)) {
        printf("Buffer overflow detected!\n");
        exit(1);
    }
    strcpy(cache[index].data, value);
}

int hashFunction(const char *key) {
    return key[0] % 10;
}

void printCache() {
    for (int i = 0; i < 10; i++) {
        printf("Cache[%d]: %s\n", i, cache[i].data);
    }
}

int main() {
    addToCache("key1", "value1");
    addToCache("key2", "value2");
    addToCache("key3", "value3");
    addToCache("key4", "value4");
    addToCache("key5", "value5");

    // Intentionally causing buffer overflow
    addToCache("key6", "This is a very long string that will cause a buffer overflow in the cache entry.");

    printCache();

    return 0;
}
