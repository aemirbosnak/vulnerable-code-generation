//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record *records;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db) {
    db->records = (Record *) malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *) malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->salary = salary;
    db->records[db->num_rows] = *record;
    db->num_rows++;
}

void delete_record(Database *db, int row) {
    if (row >= 0 && row < db->num_rows) {
        free(db->records[row].name);
        for (int i = row; i < db->num_rows - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->num_rows--;
    }
}

void update_record(Database *db, int row, char *name, int age, float salary) {
    if (row >= 0 && row < db->num_rows) {
        free(db->records[row].name);
        db->records[row].name = strdup(name);
        db->records[row].age = age;
        db->records[row].salary = salary;
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s %d %.2f\n", db->records[i].name, db->records[i].age, db->records[i].salary);
    }
}

int main() {
    Database db;
    create_database(&db);
    add_record(&db, "John Doe", 25, 50000);
    add_record(&db, "Jane Smith", 30, 60000);
    print_database(&db);
    update_record(&db, 0, "John Smith", 28, 55000);
    delete_record(&db, 1);
    print_database(&db);
    return 0;
}