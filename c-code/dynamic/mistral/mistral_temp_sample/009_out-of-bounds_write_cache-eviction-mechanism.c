#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define NUM_ENTRIES 100

typedef struct {
    char key[32];
    char value[BUFFER_SIZE];
} CacheEntry;

CacheEntry cache[NUM_ENTRIES];
int cache_size = 0;

void print_usage() {
    printf("Usage: cache_evictor <key> <value>\n");
}

int hash_function(char *key) {
    int hash = 0;
    for (int i = 0; key[i]; i++) {
        hash = (hash * 31) ^ key[i];
    }
    return hash % NUM_ENTRIES;
}

void add_entry(char *key, char *value) {
    int index = hash_function(key);
    if (cache_size == NUM_ENTRIES) {
        printf("Cache is full. Evicting an entry before adding new one.\n");
        evict_entry(index);
    }
    strcpy(cache[index].key, key);
    strcpy(cache[index].value, value);
    cache_size++;
}

void evict_entry(int index) {
    printf("Evicting entry at index %d\n", index);
    memset(cache[index].value, '\0', BUFFER_SIZE); // Out of bounds write vulnerability here
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    add_entry(argv[1], argv[2]);

    return 0;
}
