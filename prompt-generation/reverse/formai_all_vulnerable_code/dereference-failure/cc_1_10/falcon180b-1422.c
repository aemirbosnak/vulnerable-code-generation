//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int num_entries;
    int size;
} Database;

void init_database(Database *db) {
    db->entries = (Entry *) malloc(MAX_ENTRIES * sizeof(Entry));
    db->num_entries = 0;
    db->size = MAX_ENTRIES;
}

void destroy_database(Database *db) {
    free(db->entries);
}

int hash(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum % MAX_ENTRIES;
}

void insert_entry(Database *db, char *key, int value) {
    int index = hash(key);
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[index].key, key) == 0) {
            db->entries[index].value = value;
            return;
        }
        index = (index + 1) % MAX_ENTRIES;
    }
    if (db->num_entries >= db->size) {
        printf("ERROR: Database is full\n");
        return;
    }
    db->entries[index].key = strdup(key);
    db->entries[index].value = value;
    db->num_entries++;
}

int search_entry(Database *db, char *key) {
    int index = hash(key);
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[index].key, key) == 0) {
            return db->entries[index].value;
        }
        index = (index + 1) % MAX_ENTRIES;
    }
    return -1;
}

int main() {
    Database db;
    init_database(&db);

    insert_entry(&db, "apple", 5);
    insert_entry(&db, "banana", 3);
    insert_entry(&db, "cherry", 7);

    int value = search_entry(&db, "apple");
    printf("Value for apple: %d\n", value);

    destroy_database(&db);
    return 0;
}