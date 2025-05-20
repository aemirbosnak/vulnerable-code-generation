#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 64
#define MAX_CACHE_SIZE 10

typedef struct CacheEntry {
    char key[BUFFER_SIZE];
    char value[BUFFER_SIZE];
} CacheEntry;

CacheEntry cache[MAX_CACHE_SIZE];
size_t cache_index = 0;

void insert_entry(const char* key, const char* value) {
    if (cache_index == MAX_CACHE_SIZE) {
        size_t oldest_index = 0;
        for (size_t i = 1; i < cache_index; ++i)
            if (cache[i].key[0] < cache[oldest_index].key[0])
                oldest_index = i;
        memmove(cache, cache + oldest_index, (cache_index - oldest_index) * sizeof(CacheEntry));
        --cache_index;
    }
    strcpy(cache[cache_index].key, key);
    strcpy(cache[cache_index].value, value);
    ++cache_index;
}

void print_cache() {
    for (size_t i = 0; i < cache_index; ++i) {
        printf("%s: %s\n", cache[i].key, cache[i].value);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <key=value>\n", argv[0]);
        return 1;
    }

    char input[2 * BUFFER_SIZE];
    sscanf(argv[1], "%s=%s", input, input + BUFFER_SIZE);

    insert_entry(input, argv[0]);
    print_cache();
    return 0;
}
