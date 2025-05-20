#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 1024

typedef struct {
    char key[32];
    char value[64];
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
        // Intentional buffer overflow vulnerability
        char large_buffer[1024];
        strcpy(large_buffer, "Overflowed: ");
        strcat(large_buffer, cache[index].value);
        return large_buffer; // This line causes buffer overflow
    }
}

int main() {
    put("test", "This is a test");
    printf("%s\n", get("test"));
    return 0;
}
