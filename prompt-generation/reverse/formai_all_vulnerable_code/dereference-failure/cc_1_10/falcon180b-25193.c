//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char name[MAX_DATA];
    int age;
} Person;

typedef struct {
    Person **data;
    int num_rows;
    int num_cols;
} Database;

void create_database(Database *db) {
    db->data = (Person **) malloc(MAX_ROWS * sizeof(Person *));
    db->num_rows = 0;
    db->num_cols = 0;
}

void add_row(Database *db, char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    db->data[db->num_rows] = person;
    db->num_rows++;
}

void add_col(Database *db, char *name, int age) {
    Person *person = (Person *) malloc(sizeof(Person));
    strcpy(person->name, name);
    person->age = age;
    db->data[db->num_rows] = person;
    db->num_cols++;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        printf("Name: %s, Age: %d\n", db->data[i]->name, db->data[i]->age);
    }
}

int main() {
    Database db;
    create_database(&db);
    add_row(&db, "Alice", 25);
    add_col(&db, "Bob", 30);
    print_database(&db);
    return 0;
}