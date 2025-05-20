#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define MAX_ELEMENTS 100

typedef struct CacheElement {
    char key[16];
    int size;
} CacheElement;

void print_cache(CacheElement *cache, int size) {
    printf("Cache contents:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d: %s %d\n", i, cache[i].key, cache[i].size);
    }
}

void load_data(CacheElement *cache, int *index, char *line, int *cache_size) {
    char key[32];
    int size;

    if (sscanf(line, "%s %d", key, &size) != 2) {
        printf("Invalid input\n");
        return;
    }

    if (*cache_size == MAX_ELEMENTS) {
        printf("Cache is full, overwriting oldest entry\n");
        memmove(cache, &cache[1], sizeof(CacheElement) * (*index - 1));
        (*index)--;
    }

    strcpy(cache[*index].key, key);
    cache[*index].size = size;
    (*index)++;
    (*cache_size)++;
}

int main() {
    CacheElement cache[BUFFER_SIZE];
    int index = 0, cache_size = 0;

    char input[256];
    while (1) {
        printf("Enter data (key size space value): ");
        fgets(input, sizeof(input), stdin);

        load_data(cache, &index, input, &cache_size);
        print_cache(cache, cache_size);
    }

    return 0;
}
