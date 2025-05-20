//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void init_database(Database *db) {
    db->records = (Record *)malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
}

void add_record(Database *db, char *name, int age, float salary) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->name = strdup(name);
    record->age = age;
    record->salary = salary;
    db->records[db->num_rows++] = *record;
}

void print_records(Database *db) {
    int i, j;
    for (i = 0; i < db->num_rows; i++) {
        for (j = 0; j < db->num_cols; j++) {
            if (j == 0) {
                printf("%s", db->records[i].name);
            } else if (j == 1) {
                printf("%d", db->records[i].age);
            } else if (j == 2) {
                printf("%.2f", db->records[i].salary);
            }
        }
        printf("\n");
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John Doe", 25, 50000.00);
    add_record(&db, "Jane Smith", 30, 60000.00);
    add_record(&db, "Bob Johnson", 40, 70000.00);

    print_records(&db);

    return 0;
}