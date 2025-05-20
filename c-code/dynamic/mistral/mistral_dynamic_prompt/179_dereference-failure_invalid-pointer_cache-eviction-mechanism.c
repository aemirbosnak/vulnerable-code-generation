#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define KEY_LENGTH 32
#define VALUE_LENGTH 256

typedef struct {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cacheIndex = 0;

void cachePut(char* key, char* value) {
    if (cacheIndex >= CACHE_SIZE) {
        // Simulate cache eviction by randomly selecting a key to replace
        int evictionIndex = rand() % CACHE_SIZE;
        strcpy(cache[evictionIndex].key, key);
        strcpy(cache[evictionIndex].value, value);
    } else {
        strcpy(cache[cacheIndex].key, key);
        strcpy(cache[cacheIndex].value, value);
        cacheIndex++;
    }
}

void cacheGet(char* key) {
    for (int i = 0; i < cacheIndex; i++) {
        if (strcmp(cache[i].key, key) == 0) {
            printf("Found: %s\n", cache[i].value);
            return;
        }
    }

    // Simulate cache miss, dereference an invalid pointer
    printf("Not found: %s\n", cache[-1].value);
}

int main() {
    srand(time(NULL));

    cachePut("key1", "value1");
    cachePut("key2", "value2");
    cachePut("key3", "value3");

    cacheGet("key1");
    cacheGet("key4"); // Intentional invalid cache key to trigger dereference error

    return 0;
}
