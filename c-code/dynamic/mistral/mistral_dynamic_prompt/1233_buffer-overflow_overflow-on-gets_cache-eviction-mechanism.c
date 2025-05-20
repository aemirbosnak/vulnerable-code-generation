#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 64
#define CACHE_SIZE 10

typedef struct CacheEntry {
    char key[32];
    char value[BUFFER_SIZE];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_index = 0;

void evict_oldest() {
    int oldest_index = (cache_index - 1) % CACHE_SIZE;
    free(cache[oldest_index].value);
}

void put(char *key, char *value) {
    if (cache_index >= CACHE_SIZE) {
        evict_oldest();
    }
    strcpy(cache[cache_index].key, key);
    gets(cache[cache_index].value); // Vulnerable code - buffer overflow on gets
    cache_index = (cache_index + 1) % CACHE_SIZE;
}

void print_cache() {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        printf("Key: %s, Value: %s\n", cache[i].key, cache[i].value);
    }
}

int main() {
    char input[32];

    printf("Cache Eviction Mechanism\n");
    printf("Enter commands (put <key> <value> or list):\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        char command[7];
        strncpy(command, strtok(input, " "), 6);

        if (strcmp(command, "put") == 0) {
            char *key = strtok(NULL, " ");
            char *value = strtok(NULL, "\n");
            put(key, value);
        } else if (strcmp(command, "list") == 0) {
            print_cache();
        }
    }

    return 0;
}
