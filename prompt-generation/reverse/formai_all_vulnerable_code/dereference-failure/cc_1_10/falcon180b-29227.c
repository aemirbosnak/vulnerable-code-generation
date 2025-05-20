//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 200

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int num_keys;
} Database;

void database_init(Database *db, int num_keys) {
    db->records = malloc(sizeof(Record) * num_keys);
    db->num_records = 0;
    db->num_keys = num_keys;
}

void database_insert(Database *db, char *key, char *value) {
    if (db->num_records >= db->num_keys) {
        printf("Error: database is full\n");
        return;
    }

    strcpy(db->records[db->num_records].key, key);
    strcpy(db->records[db->num_records].value, value);
    db->num_records++;
}

void database_search(Database *db, char *key) {
    int i;

    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", db->records[i].key, db->records[i].value);
        }
    }
}

void database_destroy(Database *db) {
    free(db->records);
}

int main() {
    Database db;
    database_init(&db, 10);

    database_insert(&db, "apple", "red");
    database_insert(&db, "banana", "yellow");
    database_insert(&db, "orange", "orange");

    database_search(&db, "apple");
    database_search(&db, "pear");

    database_destroy(&db);

    return 0;
}