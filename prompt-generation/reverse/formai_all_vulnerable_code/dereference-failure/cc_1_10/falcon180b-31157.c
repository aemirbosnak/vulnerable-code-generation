//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100
#define MAX_COLUMN_NAME_LENGTH 20
#define MAX_VALUE_LENGTH 100

typedef struct column_t {
    char name[MAX_COLUMN_NAME_LENGTH];
    int data_type;
} column_t;

typedef struct row_t {
    char *values[MAX_COLUMNS];
} row_t;

typedef struct table_t {
    column_t columns[MAX_COLUMNS];
    row_t rows[MAX_ROWS];
    int num_rows;
    int num_columns;
} table_t;

void create_table(table_t *table, int num_columns, char **column_names, int *data_types) {
    table->num_columns = num_columns;
    for (int i = 0; i < num_columns; i++) {
        strcpy(table->columns[i].name, column_names[i]);
        table->columns[i].data_type = data_types[i];
    }
    table->num_rows = 0;
}

void add_row(table_t *table, char **values) {
    row_t row;
    for (int i = 0; i < table->num_columns; i++) {
        strcpy(row.values[i], values[i]);
    }
    table->rows[table->num_rows++] = row;
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_columns; i++) {
        printf("%-20s", table->columns[i].name);
    }
    printf("\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%-20s", table->rows[i].values[j]);
        }
        printf("\n");
    }
}

int main() {
    table_t table;
    create_table(&table, 3, (char *[]) {"ID", "Name", "Age"}, (int[]) {1, 2, 3});
    add_row(&table, (char *[]) {"1", "John", "25"});
    add_row(&table, (char *[]) {"2", "Jane", "30"});
    add_row(&table, (char *[]) {"3", "Bob", "20"});
    print_table(&table);
    return 0;
}