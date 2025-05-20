#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int data;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

void load_cache() {
    FILE *file = fopen("cache_data.txt", "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("Loading entry %d\n", i);
        if (fscanf(file, "%d", &cache[i].data) != 1) {
            fprintf(stderr, "Buffer overflow detected!\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

int main() {
    load_cache();
    return 0;
}
