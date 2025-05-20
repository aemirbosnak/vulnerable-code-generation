//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
} Record;

typedef struct {
    Record *records;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db) {
    db->records = (Record *) malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 0;
}

void destroy_database(Database *db) {
    free(db->records);
}

void add_record(Database *db, char *name, int id) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    Record record;
    strcpy(record.name, name);
    record.id = id;

    db->records[db->num_rows] = record;
    db->num_rows++;
}

int search_record(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return db->records[i].id;
        }
    }

    return -1;
}

void print_records(Database *db) {
    printf("ID\tName\n");

    for (int i = 0; i < db->num_rows; i++) {
        printf("%d\t%s\n", db->records[i].id, db->records[i].name);
    }
}

int main() {
    Database db;
    create_database(&db);

    add_record(&db, "John", 1);
    add_record(&db, "Jane", 2);
    add_record(&db, "Bob", 3);

    print_records(&db);

    int id = search_record(&db, "Jane");
    printf("ID of Jane: %d\n", id);

    destroy_database(&db);

    return 0;
}