//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 100
#define MAX_INDEX_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} entry_t;

typedef struct {
    entry_t* entries[MAX_INDEX_SIZE];
    size_t size;
} index_t;

index_t* create_index() {
    index_t* index = malloc(sizeof(index_t));
    index->size = 0;
    return index;
}

void add_entry(index_t* index, const char* key, const char* value) {
    entry_t* new_entry = malloc(sizeof(entry_t));
    strcpy(new_entry->key, key);
    strcpy(new_entry->value, value);
    index->entries[index->size] = new_entry;
    index->size++;
}

entry_t* find_entry(index_t* index, const char* key) {
    for (size_t i = 0; i < index->size; i++) {
        entry_t* entry = index->entries[i];
        if (strcmp(entry->key, key) == 0) {
            return entry;
        }
    }
    return NULL;
}

void delete_entry(index_t* index, const char* key) {
    for (size_t i = 0; i < index->size; i++) {
        entry_t* entry = index->entries[i];
        if (strcmp(entry->key, key) == 0) {
            index->entries[i] = index->entries[index->size - 1];
            index->size--;
            free(entry);
            return;
        }
    }
}

void print_index(index_t* index) {
    for (size_t i = 0; i < index->size; i++) {
        entry_t* entry = index->entries[i];
        printf("%s -> %s\n", entry->key, entry->value);
    }
}

int main() {
    index_t* index = create_index();
    add_entry(index, "key1", "value1");
    add_entry(index, "key2", "value2");
    add_entry(index, "key3", "value3");
    add_entry(index, "key4", "value4");
    add_entry(index, "key5", "value5");
    print_index(index);
    delete_entry(index, "key3");
    print_index(index);
    entry_t* entry = find_entry(index, "key2");
    if (entry) {
        printf("Found entry with key '%s' and value '%s'\n", entry->key, entry->value);
    }
    return 0;
}