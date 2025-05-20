//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *row_data[MAX_COLS];
    int num_cols;
} Row;

typedef struct {
    Row *rows;
    int num_rows;
} Table;

// function to create a new table with the given number of columns
Table* create_table(int num_cols) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->num_rows = 0;
    table->rows = (Row*) malloc(sizeof(Row));
    for (int i = 0; i < num_cols; i++) {
        table->rows[0].row_data[i] = (char*) malloc(sizeof(char) * MAX_ROWS);
        memset(table->rows[0].row_data[i], '\0', MAX_ROWS);
    }
    return table;
}

// function to add a new row to the table
void add_row(Table *table) {
    Row *new_row = (Row*) malloc(sizeof(Row));
    new_row->num_cols = table->rows[0].num_cols;
    for (int i = 0; i < new_row->num_cols; i++) {
        new_row->row_data[i] = (char*) malloc(sizeof(char) * MAX_ROWS);
        memset(new_row->row_data[i], '\0', MAX_ROWS);
    }
    table->rows = (Row*) realloc(table->rows, sizeof(Row) * (table->num_rows + 1));
    table->rows[table->num_rows] = *new_row;
    table->num_rows++;
}

// function to print the table
void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->rows[0].num_cols; j++) {
            printf("%s ", table->rows[i].row_data[j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    Table *table = create_table(3);
    add_row(table);
    add_row(table);
    add_row(table);
    add_row(table);
    add_row(table);
    print_table(table);
    return 0;
}