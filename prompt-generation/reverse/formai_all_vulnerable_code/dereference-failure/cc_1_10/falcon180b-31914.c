//Falcon-180B DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    char *name;
    int age;
    char *gender;
    Person **data;
    int row_count;
    int col_count;
} Table;

void init_table(Table *table) {
    table->row_count = 0;
    table->col_count = 0;
    table->data = NULL;
}

void add_row(Table *table, Person *person) {
    table->data = (Person **)realloc(table->data, sizeof(Person *) * ++table->row_count);
    table->data[table->row_count - 1] = person;
}

void add_col(Table *table, char *name) {
    table->col_count++;
    table->data = (Person **)realloc(table->data, sizeof(Person *) * table->row_count * table->col_count);
    for (int i = 0; i < table->row_count; i++) {
        table->data[i * table->col_count + table->col_count - 1] = NULL;
    }
}

void print_table(Table *table) {
    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            Person *person = table->data[i * table->col_count + j];
            if (person!= NULL) {
                printf("%s | %d | %s\n", person->name, person->age, person->gender);
            }
        }
        printf("\n");
    }
}

int main() {
    Table table;
    init_table(&table);

    add_col(&table, "Name");
    add_col(&table, "Age");
    add_col(&table, "Gender");

    Person *person1 = (Person *)malloc(sizeof(Person));
    person1->name = "John";
    person1->age = 25;
    person1->gender = "Male";
    add_row(&table, person1);

    Person *person2 = (Person *)malloc(sizeof(Person));
    person2->name = "Jane";
    person2->age = 30;
    person2->gender = "Female";
    add_row(&table, person2);

    print_table(&table);

    return 0;
}