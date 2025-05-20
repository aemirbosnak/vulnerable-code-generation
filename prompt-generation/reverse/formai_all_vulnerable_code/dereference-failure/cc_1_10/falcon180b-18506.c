//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LENGTH 20
#define MAX_VALUE_LENGTH 100

typedef struct entry {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

typedef struct index {
    Entry entries[MAX_ENTRIES];
    int num_entries;
} Index;

void create_index(Index* index) {
    index->num_entries = 0;
}

void add_entry(Index* index, char* key, char* value) {
    if (index->num_entries >= MAX_ENTRIES) {
        printf("Index is full!\n");
        return;
    }

    Entry entry = {
       .key = strncpy(key, index->entries[index->num_entries].key, MAX_KEY_LENGTH),
       .value = strncpy(value, index->entries[index->num_entries].value, MAX_VALUE_LENGTH)
    };

    index->entries[index->num_entries++] = entry;
}

void delete_entry(Index* index, char* key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            memmove(&index->entries[i], &index->entries[i+1], sizeof(Entry) * (index->num_entries - i - 1));
            index->num_entries--;
            return;
        }
    }
}

void search_index(Index* index, char* key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", index->entries[i].key, index->entries[i].value);
        }
    }
}

int main() {
    Index index;
    create_index(&index);

    add_entry(&index, "name", "John");
    add_entry(&index, "age", "30");
    add_entry(&index, "city", "New York");

    search_index(&index, "name");

    delete_entry(&index, "age");

    search_index(&index, "age");

    return 0;
}