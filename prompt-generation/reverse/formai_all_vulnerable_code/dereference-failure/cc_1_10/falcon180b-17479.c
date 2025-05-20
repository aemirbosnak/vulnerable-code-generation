//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_ROWS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char address[MAX_NAME_LEN];
} Person;

typedef struct {
    Person *data;
    int num_rows;
    int max_rows;
} Database;

void init_database(Database *db, int max_rows) {
    db->data = (Person *)malloc(max_rows * sizeof(Person));
    db->num_rows = 0;
    db->max_rows = max_rows;
}

void destroy_database(Database *db) {
    free(db->data);
    db->num_rows = 0;
    db->max_rows = 0;
}

int add_person(Database *db, const char *name, int age, const char *address) {
    if (db->num_rows >= db->max_rows) {
        return -1;
    }

    strncpy(db->data[db->num_rows].name, name, MAX_NAME_LEN);
    db->data[db->num_rows].age = age;
    strncpy(db->data[db->num_rows].address, address, MAX_NAME_LEN);

    db->num_rows++;

    return 0;
}

void print_person(const Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
}

void print_database(const Database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        print_person(&db->data[i]);
    }
}

int main() {
    Database db;
    init_database(&db, MAX_NUM_ROWS);

    add_person(&db, "John Doe", 30, "123 Main St.");
    add_person(&db, "Jane Smith", 28, "456 Elm St.");

    print_database(&db);

    destroy_database(&db);

    return 0;
}