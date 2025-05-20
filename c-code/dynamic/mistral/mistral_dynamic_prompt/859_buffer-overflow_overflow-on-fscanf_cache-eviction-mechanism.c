#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 16
#define CACHE_SIZE 4
#define LINE_SIZE 256

struct Line {
    char data[LINE_SIZE];
};

struct Cache {
    struct Line cache[CACHE_SIZE];
    int index;
};

void load_line(struct Cache* cache, FILE* file) {
    char line[LINE_SIZE];

    if (fgets(line, LINE_SIZE, file) != NULL) {
        strncpy(cache->cache[cache->index].data, line, LINE_SIZE - 1);
        cache->index = (cache->index + 1) % CACHE_SIZE;
    }
}

void evict_line(struct Cache* cache) {
    cache->index--;
}

void show_cache(const struct Cache* cache) {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        printf("[%d]: %s\n", i, cache->cache[i].data);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct Cache cache;
    cache.index = 0;
    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char input[BUFFER_SIZE];
    while (fgets(input, BUFFER_SIZE, file) != NULL) {
        load_line(&cache, file);
        fscanf(file, "%s", input); // VULNERABILITY: Overflow on fscanf
    }

    fclose(file);
    show_cache(&cache);
    evict_line(&cache);

    return 0;
}
