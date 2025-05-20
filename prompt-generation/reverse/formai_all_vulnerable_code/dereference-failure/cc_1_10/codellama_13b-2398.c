//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VAL_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char val[MAX_VAL_LENGTH];
} db_entry_t;

typedef struct {
    db_entry_t* entries;
    int num_entries;
} db_t;

db_t* create_db(int num_entries) {
    db_t* db = malloc(sizeof(db_t));
    db->entries = malloc(num_entries * sizeof(db_entry_t));
    db->num_entries = num_entries;
    return db;
}

void add_entry(db_t* db, const char* key, const char* val) {
    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            strcpy(db->entries[i].val, val);
            return;
        }
    }
    strcpy(db->entries[i].key, key);
    strcpy(db->entries[i].val, val);
}

char* get_val(db_t* db, const char* key) {
    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            return db->entries[i].val;
        }
    }
    return NULL;
}

void delete_entry(db_t* db, const char* key) {
    int i;
    for (i = 0; i < db->num_entries; i++) {
        if (strcmp(db->entries[i].key, key) == 0) {
            break;
        }
    }
    if (i == db->num_entries) {
        return;
    }
    for (int j = i + 1; j < db->num_entries; j++) {
        strcpy(db->entries[j - 1].key, db->entries[j].key);
        strcpy(db->entries[j - 1].val, db->entries[j].val);
    }
    db->num_entries--;
}

int main() {
    db_t* db = create_db(10);
    add_entry(db, "key1", "val1");
    add_entry(db, "key2", "val2");
    add_entry(db, "key3", "val3");
    char* val = get_val(db, "key1");
    printf("val = %s\n", val);
    delete_entry(db, "key1");
    val = get_val(db, "key1");
    printf("val = %s\n", val);
    return 0;
}