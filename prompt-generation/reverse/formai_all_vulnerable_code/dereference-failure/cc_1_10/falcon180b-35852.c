//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

typedef struct {
    char table_name[50];
    int num_cols;
    char *col_names[MAX_COLS];
    Person *data;
} Table;

void create_table(Table *table, char *name, int num_cols, char **col_names) {
    strcpy(table->table_name, name);
    table->num_cols = num_cols;
    for (int i = 0; i < num_cols; i++) {
        strcpy(table->col_names[i], col_names[i]);
    }
    table->data = (Person *) malloc(MAX_ROWS * sizeof(Person));
}

void insert_row(Table *table, int row, Person *person) {
    strcpy(table->data[row].name, person->name);
    table->data[row].age = person->age;
    strcpy(table->data[row].address, person->address);
}

void print_table(Table *table) {
    printf("Table: %s\n", table->table_name);
    printf("Columns: ");
    for (int i = 0; i < table->num_cols; i++) {
        printf("%s ", table->col_names[i]);
    }
    printf("\n");
    printf("Data:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        if (table->data[i].name[0]!= '\0') {
            printf("%s %d %s\n", table->data[i].name, table->data[i].age, table->data[i].address);
        }
    }
}

int main() {
    char name[50] = "People";
    int num_cols = 3;
    char *col_names[3] = {"Name", "Age", "Address"};
    Table table;
    create_table(&table, name, num_cols, col_names);

    Person person1 = {"John Doe", 30, "123 Main St."};
    Person person2 = {"Jane Smith", 25, "456 Elm St."};
    Person person3 = {"Bob Johnson", 40, "789 Oak St."};

    insert_row(&table, 0, &person1);
    insert_row(&table, 1, &person2);
    insert_row(&table, 2, &person3);

    print_table(&table);

    return 0;
}