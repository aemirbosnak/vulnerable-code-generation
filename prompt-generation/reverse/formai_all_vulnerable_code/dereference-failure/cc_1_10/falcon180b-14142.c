//Falcon-180B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int num_rows;
    int num_columns;
} Database;

void create_database(Database *db) {
    db->data = (Person *) malloc(MAX_ROWS * sizeof(Person));
    db->num_rows = 0;
    db->num_columns = 2;
}

void add_person(Database *db, char *name, int age) {
    db->data[db->num_rows].name = strdup(name);
    db->data[db->num_rows].age = age;
    db->num_rows++;
}

void print_database(Database *db) {
    printf("Name\tAge\n");
    for (int i = 0; i < db->num_rows; i++) {
        printf("%s\t%d\n", db->data[i].name, db->data[i].age);
    }
}

void delete_person(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            free(db->data[i].name);
            db->data[i] = db->data[db->num_rows - 1];
            db->num_rows--;
            break;
        }
    }
}

void search_database(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\n", db->data[i].name, db->data[i].age);
            break;
        }
    }
}

int main() {
    Database db;
    create_database(&db);

    add_person(&db, "John", 25);
    add_person(&db, "Jane", 30);
    add_person(&db, "Bob", 40);

    print_database(&db);

    delete_person(&db, "Jane");

    print_database(&db);

    search_database(&db, "John");

    return 0;
}