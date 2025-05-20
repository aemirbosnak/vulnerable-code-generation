//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_COLUMNS 10
#define MAX_ROWS 10

typedef struct {
    char *name;
    int age;
    float salary;
} DataRow;

typedef struct {
    char *name;
    int size;
    int num_rows;
    int num_cols;
    DataRow **data;
} DataTable;

DataRow *create_data_row(char *name, int age, float salary) {
    DataRow *row = (DataRow *)malloc(sizeof(DataRow));
    row->name = strdup(name);
    row->age = age;
    row->salary = salary;
    return row;
}

DataTable *create_data_table(char *name, int num_rows, int num_cols) {
    DataTable *table = (DataTable *)malloc(sizeof(DataTable));
    table->name = strdup(name);
    table->size = num_rows * num_cols;
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (DataRow **)malloc(sizeof(DataRow *) * table->size);
    return table;
}

void add_data_row(DataTable *table, int row_num, DataRow *row) {
    table->data[row_num] = row;
}

void print_data_table(DataTable *table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            DataRow *row = table->data[i * table->num_cols + j];
            printf("%s | %d | $%.2f\n", row->name, row->age, row->salary);
        }
        printf("\n");
    }
}

int main() {
    DataTable *table = create_data_table("Employees", 3, 3);
    add_data_row(table, 0, create_data_row("John", 30, 50000));
    add_data_row(table, 1, create_data_row("Jane", 25, 45000));
    add_data_row(table, 2, create_data_row("Bob", 35, 60000));
    print_data_table(table);
    return 0;
}