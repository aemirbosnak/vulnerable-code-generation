#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int key;
    char data[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

int hash(int key) {
    return key % CACHE_SIZE;
}

void insert(int key, const char* value) {
    int index = hash(key);
    while (cache[index].key != -1) {
        index = (index + 1) % CACHE_SIZE;
    }
    cache[index].key = key;
    snprintf(cache[index].data, sizeof(cache[index].data), "%s", value);
}

char* get(int key) {
    int index = hash(key);
    while (cache[index].key != -1) {
        if (cache[index].key == key) {
            return cache[index].data;
        }
        index = (index + 1) % CACHE_SIZE;
    }
    return NULL;
}

void evict() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            cache[i].key = -1;
        }
    }
}

int main() {
    evict();
    printf("Cache initialized.\n");

    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    int key;
    char value[1024];
    while (fscanf(file, "%d %s", &key, value) != EOF) {
        insert(key, value);
    }

    fclose(file);

    printf("Cache populated.\n");

    // Vulnerability: Buffer overflow in fscanf
    int vulnerable_key;
    char vulnerable_value[1024];
    printf("Enter key and value to insert (vulnerable input): ");
    fscanf(stdin, "%d %s", &vulnerable_key, vulnerable_value);

    insert(vulnerable_key, vulnerable_value);

    printf("Cache after insertion:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            printf("Key: %d, Value: %s\n", cache[i].key, cache[i].data);
        }
    }

    return EXIT_SUCCESS;
}
