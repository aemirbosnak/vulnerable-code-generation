//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *table_name;
    int num_rows;
    int num_cols;
    char **data;
} Table;

void create_table(Table *table, char *table_name, int num_rows, int num_cols) {
    table->table_name = strdup(table_name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * MAX_DATA_SIZE);
        memset(table->data[i], 0, num_cols * MAX_DATA_SIZE);
    }
}

void insert_data(Table *table, int row, int col, char *data) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        strncat(table->data[row], data, MAX_DATA_SIZE);
    } else {
        printf("Invalid row or column\n");
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->table_name);
    printf("Num Rows: %d\n", table->num_rows);
    printf("Num Cols: %d\n", table->num_cols);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table, "example", 3, 3);
    insert_data(&table, 0, 0, "Name");
    insert_data(&table, 0, 1, "Age");
    insert_data(&table, 0, 2, "Gender");
    insert_data(&table, 1, 0, "John");
    insert_data(&table, 1, 1, "25");
    insert_data(&table, 1, 2, "Male");
    insert_data(&table, 2, 0, "Jane");
    insert_data(&table, 2, 1, "30");
    insert_data(&table, 2, 2, "Female");
    print_table(&table);
    return 0;
}