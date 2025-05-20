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

void addToCache(char *key, char *value) {
    int index = hashFunction(key);
    strcpy(cache[index].data, value);
}

int hashFunction(char *key) {
    return key[0] % 10;
}

void evictFromCache() {
    for (int i = 0; i < 10; i++) {
        memset(&cache[i], 0, sizeof(CacheEntry));
    }
}

int main() {
    addToCache("key1", "value1");
    addToCache("key2", "value2");

    // Intentional buffer overflow to demonstrate cache eviction vulnerability
    addToCache("key3", "this_is_a_very_long_string_that_will_overflow_the_cache_entry_data_buffer_and_cause_an_exploit");

    evictFromCache();

    return 0;
}
