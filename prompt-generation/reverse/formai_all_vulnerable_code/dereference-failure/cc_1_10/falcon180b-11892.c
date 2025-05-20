//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct {
    char *name;
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
    db->num_cols = 3;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *) malloc(sizeof(Record));
    record->name = name;
    record->age = age;
    record->salary = salary;
    db->data[db->num_rows] = *record;
    db->num_rows++;
}

void print_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Salary: $%.2f\n", record->salary);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_record(&db->data[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John Doe", 25, 50000);
    add_record(&db, "Jane Smith", 30, 60000);

    print_database(&db);

    return 0;
}