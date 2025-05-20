//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100
#define MAX_RECORDS 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int count;
} Database;

void database_init(Database *db) {
    db->records = calloc(MAX_RECORDS, sizeof(Record));
    db->count = 0;
}

void database_add(Database *db, char *key, char *value) {
    if (db->count >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }

    strncpy(db->records[db->count].key, key, MAX_KEY_LENGTH);
    strncpy(db->records[db->count].value, value, MAX_VALUE_LENGTH);

    db->count++;
}

void database_search(Database *db, char *key) {
    int i;

    for (i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("Key: %s\nValue: %s\n", db->records[i].key, db->records[i].value);
            return;
        }
    }

    printf("Key not found\n");
}

int main() {
    Database db;
    database_init(&db);

    database_add(&db, "John", "30");
    database_add(&db, "Jane", "25");
    database_add(&db, "Doe", "40");

    database_search(&db, "John");
    database_search(&db, "Jane");
    database_search(&db, "Doe");

    return 0;
}