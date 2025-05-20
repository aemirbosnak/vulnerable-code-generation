//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Row;

typedef struct {
    char table_name[MAX_DATA_SIZE];
    int num_rows;
    int num_cols;
    Row *data;
} Table;

void create_table(Table *table, char *name, int num_rows, int num_cols) {
    strcpy(table->table_name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Row *)malloc(num_rows * sizeof(Row));
    for (int i = 0; i < num_rows; i++) {
        table->data[i].age = 0;
        table->data[i].salary = 0.0;
    }
}

void insert_row(Table *table, int row_num, char *name, int age, float salary) {
    strcpy(table->data[row_num].name, name);
    table->data[row_num].age = age;
    table->data[row_num].salary = salary;
}

void delete_row(Table *table, int row_num) {
    for (int i = row_num; i < table->num_rows - 1; i++) {
        table->data[i] = table->data[i+1];
    }
    table->num_rows--;
}

void update_row(Table *table, int row_num, char *name, int age, float salary) {
    strcpy(table->data[row_num].name, name);
    table->data[row_num].age = age;
    table->data[row_num].salary = salary;
}

void print_table(Table *table) {
    printf("Table Name: %s\n", table->table_name);
    printf("Number of Rows: %d\n", table->num_rows);
    printf("Number of Columns: %d\n", table->num_cols);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        printf("Row %d: %s %d %.2f\n", i+1, table->data[i].name, table->data[i].age, table->data[i].salary);
    }
}

int main() {
    Table table;
    create_table(&table, "Employees", 10, 3);
    insert_row(&table, 1, "John Doe", 30, 50000.00);
    insert_row(&table, 2, "Jane Smith", 25, 45000.00);
    print_table(&table);
    update_row(&table, 1, "John Smith", 35, 60000.00);
    delete_row(&table, 2);
    print_table(&table);
    return 0;
}