#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 1024

typedef struct {
    char key[32];
    char value[CACHE_SIZE];
} CacheEntry;

CacheEntry cache[10];

void addToCache(const char* key, const char* value) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(cache[i].key, "") == 0) {
            strncpy(cache[i].key, key, sizeof(cache[i].key));
            strncpy(cache[i].value, value, sizeof(cache[i].value));
            return;
        }
    }
}

char* getFromCache(const char* key) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(cache[i].key, key) == 0) {
            return cache[i].value;
        }
    }
    return NULL;
}

int main() {
    addToCache("test", "This is a test");
    printf("%s\n", getFromCache("test"));

    // Deliberate buffer overflow vulnerability
    char largeKey[64];
    strcpy(largeKey, "large_key_");
    memset(largeKey + strlen(largeKey), 'A', 64 - strlen(largeKey));

    addToCache(largeKey, "Overflowed");

    // This should overwrite adjacent memory
    printf("%s\n", getFromCache("test"));

    return 0;
}
