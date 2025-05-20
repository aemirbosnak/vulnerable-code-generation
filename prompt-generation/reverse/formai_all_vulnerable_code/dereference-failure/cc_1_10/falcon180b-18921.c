//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
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
} Database;

void init_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void add_record(Database *db, char *key, char *value) {
    Record *record = malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    db->records = realloc(db->records, sizeof(Record) * ++db->num_records);
    db->records[db->num_records - 1] = *record;
}

void print_records(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%s -> %s\n", db->records[i].key, db->records[i].value);
    }
}

void free_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        free(db->records[i].key);
        free(db->records[i].value);
    }
    free(db->records);
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "apple", "red");
    add_record(&db, "banana", "yellow");
    add_record(&db, "cherry", "red");

    print_records(&db);

    free_database(&db);

    return 0;
}