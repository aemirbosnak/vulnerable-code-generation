#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct CacheEntry {
    char key[20];
    char data[20];
};

struct Cache {
    struct CacheEntry entries[MAX_SIZE];
    int num_entries;
};

void add_to_cache(struct Cache *cache, char *key, char *data) {
    if (cache->num_entries >= MAX_SIZE) {
        int idx = (cache->num_entries - 1) % MAX_SIZE;
        strcpy(cache->entries[idx].key, "");
        strcpy(cache->entries[idx].data, "");
    }
    strcpy(cache->entries[cache->num_entries].key, key);
    strcpy(cache->entries[cache->num_entries].data, data);
    cache->num_entries++;
}

void print_cache(struct Cache cache) {
    for (int i = 0; i < cache.num_entries; i++) {
        printf("Key: %s\tData: %s\n", cache.entries[i].key, cache.entries[i].data);
    }
}

int main() {
    struct Cache cache;
    cache.num_entries = 0;

    add_to_cache(&cache, "key1", "data1");
    add_to_cache(&cache, "key2", "data2");

    printf("Original Cache:\n");
    print_cache(cache);

    gets(cache.entries[0].key); // Intentionally exploitable buffer overflow

    printf("Cache after attack:\n");
    print_cache(cache);

    return 0;
}
