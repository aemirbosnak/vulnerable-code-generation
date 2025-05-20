//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Database;

void init_database(Database *db, int max_records) {
    db->records = (Record *)malloc(sizeof(Record) * max_records);
    db->num_records = 0;
    db->max_records = max_records;
}

void add_record(Database *db, char *key, char *value) {
    if (db->num_records >= db->max_records) {
        printf("Error: database is full\n");
        return;
    }

    Record *record = &db->records[db->num_records];
    strcpy(record->key, key);
    strcpy(record->value, value);

    db->num_records++;
}

void search_record(Database *db, char *key) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        Record *record = &db->records[i];
        if (strcmp(record->key, key) == 0) {
            printf("Found record with key '%s': %s\n", key, record->value);
            return;
        }
    }

    printf("Record not found\n");
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "apple", "red");
    add_record(&db, "banana", "yellow");
    add_record(&db, "orange", "orange");

    search_record(&db, "apple");
    search_record(&db, "mango");

    return 0;
}