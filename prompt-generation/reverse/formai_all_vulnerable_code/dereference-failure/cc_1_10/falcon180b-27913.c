//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = (Record *) malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *) malloc(sizeof(Record));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    db->data[db->num_rows++] = *record;
}

void print_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Salary: $%.2f\n\n", record->salary);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_record(&db->data[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "Alice", 25, 50000.00);
    add_record(&db, "Bob", 30, 60000.00);
    add_record(&db, "Charlie", 35, 70000.00);

    print_database(&db);

    return 0;
}