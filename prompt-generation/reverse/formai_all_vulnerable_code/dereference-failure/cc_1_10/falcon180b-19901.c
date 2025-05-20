//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int id;
} record_t;

typedef struct {
    record_t *data;
    int num_rows;
    int num_columns;
} database_t;

void create_database(database_t *db) {
    db->data = (record_t *)malloc(MAX_ROWS * sizeof(record_t));
    db->num_rows = 0;
    db->num_columns = 0;
}

void add_column(database_t *db, char *name) {
    db->num_columns++;
}

void add_record(database_t *db, char *name, int id) {
    record_t *rec = (record_t *)malloc(sizeof(record_t));
    rec->name = strdup(name);
    rec->id = id;

    if (db->num_rows == MAX_ROWS) {
        printf("Error: Database is full.\n");
        exit(1);
    }

    db->data[db->num_rows++] = *rec;
}

void print_database(database_t *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s %d\n", db->data[i].name, db->data[i].id);
    }
}

int main() {
    database_t db;
    create_database(&db);

    add_column(&db, "Name");
    add_column(&db, "ID");

    add_record(&db, "John", 1);
    add_record(&db, "Jane", 2);

    print_database(&db);

    return 0;
}