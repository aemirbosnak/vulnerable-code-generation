#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 1024

typedef struct {
    char key[32];
    char value[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

int hash(const char *key) {
    int hash = 0;
    while (*key) {
        hash = (hash << 5) - hash + *key++;
    }
    return abs(hash % CACHE_SIZE);
}

void put(const char *key, const char *value) {
    int index = hash(key);
    strcpy(cache[index].key, key);
    strcpy(cache[index].value, value);
}

char* get(const char *key) {
    int index = hash(key);
    if (strcmp(cache[index].key, key) == 0) {
        return cache[index].value;
    } else {
        return NULL;
    }
}

int main() {
    // Simulate a large number of puts to fill up the cache
    for (int i = 0; i < 2048; i++) {
        char key[32];
        sprintf(key, "key%d", i);
        put(key, "data");
    }

    // Attempt to get a value that should cause an overflow
    char key[32] = "key";
    strcat(key, "A"); // This will overflow the buffer
    printf("%s\n", get(key));

    return 0;
}
