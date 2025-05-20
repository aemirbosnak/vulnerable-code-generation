//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    Person **rows;
    int num_rows;
    int num_cols;
} Table;

void create_table(Table *table) {
    table->rows = (Person **)malloc(MAX_ROWS * sizeof(Person *));
    table->num_rows = 0;
    table->num_cols = 3;
}

void add_row(Table *table, Person *person) {
    table->rows[table->num_rows] = person;
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s %d %s\n", table->rows[i]->name, table->rows[i]->age, table->rows[i]->gender);
    }
}

int main() {
    Table table;
    create_table(&table);

    Person *person1 = (Person *)malloc(sizeof(Person));
    person1->name = "John";
    person1->age = 30;
    person1->gender = "Male";
    add_row(&table, person1);

    Person *person2 = (Person *)malloc(sizeof(Person));
    person2->name = "Jane";
    person2->age = 25;
    person2->gender = "Female";
    add_row(&table, person2);

    print_table(&table);

    return 0;
}