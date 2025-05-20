//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: standalone
/*
 *  Unique C Database Indexing System
 *  Example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_VAL_LENGTH 128

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VAL_LENGTH];
} entry;

typedef struct {
    int size;
    entry* data;
} database;

database* create_database() {
    database* db = malloc(sizeof(database));
    db->size = 0;
    db->data = NULL;
    return db;
}

void insert_entry(database* db, const char* key, const char* value) {
    int i;
    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].key, key) == 0) {
            printf("Key already exists\n");
            return;
        }
    }
    db->data = realloc(db->data, (db->size + 1) * sizeof(entry));
    strcpy(db->data[db->size].key, key);
    strcpy(db->data[db->size].value, value);
    db->size++;
}

void print_database(database* db) {
    int i;
    for (i = 0; i < db->size; i++) {
        printf("%s -> %s\n", db->data[i].key, db->data[i].value);
    }
}

void free_database(database* db) {
    free(db->data);
    free(db);
}

int main() {
    database* db = create_database();
    insert_entry(db, "key1", "value1");
    insert_entry(db, "key2", "value2");
    insert_entry(db, "key3", "value3");
    print_database(db);
    free_database(db);
    return 0;
}