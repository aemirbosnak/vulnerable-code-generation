//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *city;
} Person;

typedef struct {
    Person **rows;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->rows = (Person **)malloc(MAX_ROWS * sizeof(Person *));
    db->num_rows = 0;
    db->num_cols = 3;
}

void add_row(Database *db, Person *row) {
    db->rows[db->num_rows] = row;
    db->num_rows++;
}

int main() {
    Database db;
    init_database(&db);

    Person *row1 = (Person *)malloc(sizeof(Person));
    row1->name = "John";
    row1->age = 25;
    row1->city = "New York";
    add_row(&db, row1);

    Person *row2 = (Person *)malloc(sizeof(Person));
    row2->name = "Jane";
    row2->age = 30;
    row2->city = "Los Angeles";
    add_row(&db, row2);

    printf("Name\tAge\tCity\n");
    for (int i = 0; i < db.num_rows; i++) {
        printf("%s\t%d\t%s\n", db.rows[i]->name, db.rows[i]->age, db.rows[i]->city);
    }

    return 0;
}