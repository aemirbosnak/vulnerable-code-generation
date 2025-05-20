//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db, int num_rows, int num_cols) {
    db->data = malloc(num_rows * sizeof(Record));
    db->num_rows = num_rows;
    db->num_cols = num_cols;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            sprintf(db->data[i].name, "Record %d_%d", i, j);
            db->data[i].age = i * j;
            db->data[i].salary = i * j * 0.1;
        }
    }
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("Record %d:\n", i);
        printf("Name: %s\n", db->data[i].name);
        printf("Age: %d\n", db->data[i].age);
        printf("Salary: $%.2f\n\n", db->data[i].salary);
    }
}

int main() {
    Database db;
    create_database(&db, 5, 3);
    print_database(&db);

    return 0;
}