//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 100
#define MAX_INDEX_LEN 10

typedef struct entry {
    char name[MAX_ENTRY_LEN];
    int value;
} Entry;

typedef struct index {
    char name[MAX_INDEX_LEN];
    int count;
    Entry *entries;
} Index;

void create_index(Index *index, char *name) {
    strcpy(index->name, name);
    index->count = 0;
    index->entries = (Entry *) malloc(MAX_ENTRIES * sizeof(Entry));
}

void add_entry(Index *index, char *name, int value) {
    int i;
    for (i = 0; i < index->count; i++) {
        if (strcmp(index->entries[i].name, name) == 0) {
            index->entries[i].value = value;
            return;
        }
    }
    strcpy(index->entries[index->count].name, name);
    index->entries[index->count].value = value;
    index->count++;
}

void search_index(Index *index, char *name) {
    int i;
    for (i = 0; i < index->count; i++) {
        if (strcmp(index->entries[i].name, name) == 0) {
            printf("Name: %s, Value: %d\n", index->entries[i].name, index->entries[i].value);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    Index index;
    char name[MAX_ENTRY_LEN];
    int value;

    create_index(&index, "Test Index");

    printf("Enter name and value for entry:\n");
    scanf("%s %d", name, &value);
    add_entry(&index, name, value);

    printf("Search for an entry:\n");
    scanf("%s", name);
    search_index(&index, name);

    return 0;
}