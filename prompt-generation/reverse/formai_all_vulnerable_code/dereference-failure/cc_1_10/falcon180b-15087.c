//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

void create_table(Table *table) {
    table->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->num_rows = 0;
    table->num_cols = 0;
}

void add_row(Table *table, char *row_data) {
    int row_size = strlen(row_data);
    if (row_size > MAX_ROW_SIZE) {
        printf("Error: Row size exceeds maximum limit.\n");
        return;
    }
    table->data[table->num_rows] = (char *)malloc(row_size + 1);
    strcpy(table->data[table->num_rows], row_data);
    table->num_rows++;
}

void add_col(Table *table, char *col_data) {
    int col_size = strlen(col_data);
    if (col_size > MAX_ROW_SIZE) {
        printf("Error: Column size exceeds maximum limit.\n");
        return;
    }
    table->num_cols++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table);

    add_col(&table, "ID");
    add_col(&table, "Name");
    add_col(&table, "Age");

    add_row(&table, "1 John 25");
    add_row(&table, "2 Jane 30");
    add_row(&table, "3 Bob 40");

    print_table(&table);

    return 0;
}