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

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int key, value;
        if (sscanf(line, "%d %d", &key, &value) != 2) {
            fprintf(stderr, "Invalid input format\n");
            continue;
        }
        if (key >= CACHE_SIZE) {
            fprintf(stderr, "Key out of bounds\n");
            continue;
        }
        cache[key].data = value;
    }

    fclose(file);
}

int main() {
    load_cache();
    return 0;
}
