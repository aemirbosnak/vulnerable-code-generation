//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int capacity;
} Database;

void init_database(Database *db, int capacity) {
    db->records = (Record *)malloc(capacity * sizeof(Record));
    db->num_records = 0;
    db->capacity = capacity;
}

void destroy_database(Database *db) {
    free(db->records);
}

int is_full(Database *db) {
    return db->num_records == db->capacity;
}

int is_empty(Database *db) {
    return db->num_records == 0;
}

void add_record(Database *db, char *key, char *data) {
    if (is_full(db)) {
        printf("Database is full.\n");
        return;
    }

    strcpy(db->records[db->num_records].key, key);
    strcpy(db->records[db->num_records].data, data);
    db->num_records++;
}

void search_record(Database *db, char *key) {
    int i;

    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("Record found:\nKey: %s\nData: %s\n", db->records[i].key, db->records[i].data);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    Database db;
    init_database(&db, 10);

    add_record(&db, "John", "Doe");
    add_record(&db, "Jane", "Doe");
    add_record(&db, "Bob", "Smith");

    search_record(&db, "John");
    search_record(&db, "Bob");
    search_record(&db, "Alice");

    destroy_database(&db);

    return 0;
}