#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_KEYS 1000
#define CACHE_SIZE 64

typedef struct CacheEntry {
    char key[32];
    char value[BUFFER_SIZE];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int count = 0;

void set(const char* key, const char* value) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (!cache[i].key[0]) {
            strcpy(cache[i].key, key);
            strcpy(cache[i].value, value);
            ++count;
            return;
        }
    }

    int victim = (count % CACHE_SIZE);
    memcpy(cache[victim].value + BUFFER_SIZE, value, BUFFER_SIZE);
}

int main(int argc, char** argv) {
    for (int i = 0; i < MAX_KEYS; ++i) {
        char key[32];
        sprintf(key, "key%d", i);
        char value[BUFFER_SIZE];
        sprintf(value, "val%d", i);
        set(key, value);
    }

    set("oob", "out of bounds"); // OUT OF BOUNDS WRITE VULNERABILITY HERE

    return 0;
}
