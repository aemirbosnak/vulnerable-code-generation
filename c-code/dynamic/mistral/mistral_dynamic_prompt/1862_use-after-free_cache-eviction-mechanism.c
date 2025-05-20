#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CACHE_SIZE 10
#define CACHE_ENTRY_SIZE 128

typedef struct CacheEntry {
    char key[CACHE_ENTRY_SIZE];
    char value[CACHE_ENTRY_SIZE];
    struct CacheEntry* next;
} CacheEntry;

CacheEntry* head = NULL;

void add_to_cache(char* key, char* value) {
    CacheEntry* new_entry = (CacheEntry*)malloc(sizeof(CacheEntry));
    strcpy(new_entry->key, key);
    strcpy(new_entry->value, value);
    new_entry->next = head;
    head = new_entry;

    if (MAX_CACHE_SIZE < MAX_CACHE_SIZE - 1) {
        CacheEntry* to_free = head;
        head = head->next;
        free(to_free);
    }
}

char* get_from_cache(char* key) {
    CacheEntry* current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    add_to_cache("key1", "value1");
    add_to_cache("key2", "value2");
    add_to_cache("key3", "value3");

    printf("Get key1: %s\n", get_from_cache("key1"));
    head->next = NULL; // Free head->next later without free(head)
    return 0;
}
