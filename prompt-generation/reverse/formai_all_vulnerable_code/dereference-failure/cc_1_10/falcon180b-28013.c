//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char *key;
    int value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int numEntries;
} Index;

void index_init(Index *index) {
    index->entries = malloc(MAX_INDEX_SIZE * sizeof(IndexEntry));
    index->numEntries = 0;
}

void index_add(Index *index, char *key, int value) {
    IndexEntry *entry = malloc(sizeof(IndexEntry));
    entry->key = strdup(key);
    entry->value = value;
    index->entries[index->numEntries++] = *entry;
}

int index_search(Index *index, char *key) {
    for (int i = 0; i < index->numEntries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return -1;
}

void index_destroy(Index *index) {
    for (int i = 0; i < index->numEntries; i++) {
        free(index->entries[i].key);
    }
    free(index->entries);
    index->entries = NULL;
    index->numEntries = 0;
}

int main() {
    Index index;
    index_init(&index);
    index_add(&index, "apple", 5);
    index_add(&index, "banana", 3);
    index_add(&index, "cherry", 7);
    int value = index_search(&index, "banana");
    printf("Value for 'banana': %d\n", value);
    index_destroy(&index);
    return 0;
}