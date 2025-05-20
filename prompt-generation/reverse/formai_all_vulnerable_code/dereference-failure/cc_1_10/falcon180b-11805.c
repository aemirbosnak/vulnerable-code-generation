//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_NUM_FIELDS 10
#define MAX_FIELD_SIZE 100
#define MAX_RECORD_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    int num_fields;
    char fields[MAX_NUM_FIELDS][MAX_FIELD_SIZE];
    int record_size;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void create_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void add_record(Database *db, Record *record) {
    db->records = realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records] = *record;
    db->num_records++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Name: %s\n", db->records[i].name);
        printf("Number of fields: %d\n", db->records[i].num_fields);
        for (int j = 0; j < db->records[i].num_fields; j++) {
            printf("Field %d: %s\n", j + 1, db->records[i].fields[j]);
        }
        printf("\n");
    }
}

int main() {
    Database db;
    create_database(&db);

    Record record1 = {"John Doe", 2, {"Name", "Age"}, 2};
    Record record2 = {"Jane Smith", 3, {"Name", "Age", "Gender"}, 3};
    Record record3 = {"Bob Johnson", 1, {"Name"}, 1};

    add_record(&db, &record1);
    add_record(&db, &record2);
    add_record(&db, &record3);

    print_database(&db);

    return 0;
}