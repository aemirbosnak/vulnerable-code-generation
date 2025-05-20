//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void create_database(Database *db) {
    db->records = (Record *)malloc(MAX_NUM_KEYS * sizeof(Record));
    db->num_records = 0;
}

void destroy_database(Database *db) {
    free(db->records);
}

int add_record(Database *db, char *key, char *value) {
    if (db->num_records >= MAX_NUM_KEYS) {
        return 0;
    }
    strcpy(db->records[db->num_records].key, key);
    strcpy(db->records[db->num_records].value, value);
    db->num_records++;
    return 1;
}

int search_record(Database *db, char *key, char *value) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            strcpy(value, db->records[i].value);
            return 1;
        }
    }
    return 0;
}

void print_database(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("Key: %s\tValue: %s\n", db->records[i].key, db->records[i].value);
    }
}

int main() {
    Database db;
    create_database(&db);
    add_record(&db, "Name", "John");
    add_record(&db, "Age", "25");
    add_record(&db, "City", "New York");
    print_database(&db);
    printf("Search for Name: %s\n", db.records[0].value);
    printf("Search for Age: %s\n", db.records[1].value);
    printf("Search for City: %s\n", db.records[2].value);
    destroy_database(&db);
    return 0;
}