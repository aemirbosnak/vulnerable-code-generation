//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1024
#define MAX_VALUE_SIZE 4096
#define HASH_TABLE_SIZE 1024
#define HASH_FUNCTION(key, size) (hash(key) % size)

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash;
}

typedef struct {
    char *key;
    char *value;
} HashEntry;

typedef struct {
    HashEntry *entries;
    int count;
} HashTable;

void hash_init(HashTable *table) {
    table->entries = (HashEntry *) malloc(HASH_TABLE_SIZE * sizeof(HashEntry));
    memset(table->entries, 0, HASH_TABLE_SIZE * sizeof(HashEntry));
    table->count = 0;
}

void hash_insert(HashTable *table, char *key, char *value) {
    int index = HASH_FUNCTION(key, HASH_TABLE_SIZE);
    HashEntry *entry = &table->entries[index];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            strcpy(entry->value, value);
            return;
        }
        entry++;
    }
    entry->key = strdup(key);
    entry->value = strdup(value);
    table->count++;
}

char *hash_search(HashTable *table, char *key) {
    int index = HASH_FUNCTION(key, HASH_TABLE_SIZE);
    HashEntry *entry = &table->entries[index];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry++;
    }
    return NULL;
}

void hash_delete(HashTable *table, char *key) {
    int index = HASH_FUNCTION(key, HASH_TABLE_SIZE);
    HashEntry *entry = &table->entries[index];
    while (entry->key!= NULL) {
        if (strcmp(entry->key, key) == 0) {
            free(entry->key);
            free(entry->value);
            entry->key = NULL;
            entry->value = NULL;
            table->count--;
            return;
        }
        entry++;
    }
}

void hash_destroy(HashTable *table) {
    int i;
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        HashEntry *entry = &table->entries[i];
        while (entry->key!= NULL) {
            free(entry->key);
            free(entry->value);
            entry->key = NULL;
            entry->value = NULL;
            entry++;
        }
    }
    free(table->entries);
}

int main() {
    HashTable table;
    hash_init(&table);
    char *key = "name";
    char *value = "John";
    hash_insert(&table, key, value);
    char *result = hash_search(&table, key);
    printf("%s = %s\n", key, result);
    hash_delete(&table, key);
    hash_destroy(&table);
    return 0;
}