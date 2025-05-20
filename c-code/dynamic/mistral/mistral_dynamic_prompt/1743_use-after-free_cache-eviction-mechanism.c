#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 8
#define KEY_SIZE 16
#define VALUE_SIZE 128

typedef struct CacheEntry {
    char key[KEY_SIZE];
    char value[VALUE_SIZE];
    struct CacheEntry* next;
} CacheEntry;

CacheEntry* cache[CACHE_SIZE];

void createCache() {
    int i;
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i] = NULL;
    }
}

void put(char* key, char* value) {
    int index = hash(key);
    CacheEntry* newEntry = malloc(sizeof(CacheEntry));
    strcpy(newEntry->key, key);
    strcpy(newEntry->value, value);
    newEntry->next = cache[index];
    cache[index] = newEntry;
}

char* get(char* key) {
    int index = hash(key);
    CacheEntry* current = cache[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            void* temp = current;
            current = current->next;
            free(temp);
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

int hash(char* key) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    }
    return hash % CACHE_SIZE;
}

int main() {
    createCache();

    put("key1", "value1");
    put("key2", "value2");
    put("key3", "value3");
    put("key4", "value4");
    put("key5", "value5");

    printf("Retrieved value: %s\n", get("key1")); // Use after free vulnerability occurs here

    return 0;
}
