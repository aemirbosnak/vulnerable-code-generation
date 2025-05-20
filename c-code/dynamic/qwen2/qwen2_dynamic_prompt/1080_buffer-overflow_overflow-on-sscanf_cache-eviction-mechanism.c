#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int key;
    char value[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

int find_empty_slot() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key == -1) {
            return i;
        }
    }
    return -1;
}

void evict_cache() {
    int oldest_index = 0;
    for (int i = 1; i < CACHE_SIZE; i++) {
        if (cache[i].key < cache[oldest_index].key) {
            oldest_index = i;
        }
    }
    cache[oldest_index].key = -1;
}

void add_to_cache(int key, const char* value) {
    int index = find_empty_slot();
    if (index == -1) {
        evict_cache();
        index = find_empty_slot();
    }
    cache[index].key = key;
    snprintf(cache[index].value, sizeof(cache[index].value), "%s", value);
}

void print_cache() {
    printf("Cache:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            printf("Key: %d, Value: %s\n", cache[i].key, cache[i].value);
        } else {
            printf("Slot %d is empty\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;
    }

    char input[256];
    while (1) {
        printf("Enter key and value (e.g., '1 hello'): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%d %s", &cache[0].key, cache[0].value) != 2) {
            printf("Invalid input format!\n");
            continue;
        }

        add_to_cache(cache[0].key, cache[0].value);
        print_cache();
    }

    return 0;
}
