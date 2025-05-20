//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    char address[MAX_DATA_SIZE];
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = (Record *)malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
}

void destroy_database(Database *db) {
    free(db->data);
}

void add_record(Database *db, char *name, int age, char *address) {
    if (db->num_rows >= MAX_ROWS) {
        printf("Error: maximum number of rows reached.\n");
        return;
    }

    Record *record = &db->data[db->num_rows];
    strcpy(record->name, name);
    record->age = age;
    strcpy(record->address, address);

    db->num_rows++;
}

void print_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Address: %s\n", record->address);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_record(&db->data[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John Doe", 25, "123 Main St");
    add_record(&db, "Jane Smith", 30, "456 Elm St");

    print_database(&db);

    destroy_database(&db);

    return 0;
}