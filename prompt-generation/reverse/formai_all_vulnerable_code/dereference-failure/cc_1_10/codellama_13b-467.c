//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
// unique_c_db_indexing_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

typedef struct {
    entry_t* entries;
    int num_entries;
    int capacity;
} db_t;

void init_db(db_t* db, int capacity) {
    db->entries = malloc(capacity * sizeof(entry_t));
    db->num_entries = 0;
    db->capacity = capacity;
}

void insert_entry(db_t* db, char* key, char* value) {
    if (db->num_entries == db->capacity) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(db->entries[db->num_entries].key, key);
    strcpy(db->entries[db->num_entries].value, value);
    db->num_entries++;
}

char* get_value(db_t* db, char* key) {
    for (int i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].value;
        }
    }

    return NULL;
}

void free_db(db_t* db) {
    free(db->entries);
    db->entries = NULL;
    db->num_entries = 0;
    db->capacity = 0;
}

int main() {
    db_t db;
    init_db(&db, 10);

    insert_entry(&db, "key1", "value1");
    insert_entry(&db, "key2", "value2");
    insert_entry(&db, "key3", "value3");

    char* value = get_value(&db, "key2");
    printf("Value: %s\n", value);

    free_db(&db);

    return 0;
}