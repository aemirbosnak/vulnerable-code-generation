//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROWS_PER_QUERY 10
#define MAX_COLS_PER_QUERY 10

typedef struct {
    char **values;
    int num_rows;
    int num_cols;
} Table;

Table *create_table() {
    Table *table = (Table *)malloc(sizeof(Table));
    table->values = (char **)malloc(MAX_ROWS * sizeof(char *));
    table->num_rows = 0;
    table->num_cols = 0;
    return table;
}

void add_row(Table *table, char *row) {
    table->values[table->num_rows] = (char *)malloc((strlen(row) + 1) * sizeof(char));
    strcpy(table->values[table->num_rows], row);
    table->num_rows++;
}

void add_col(Table *table, char *col) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        table->values[i] = (char *)realloc(table->values[i], strlen(table->values[i]) + strlen(col) + 2);
        strcat(table->values[i], col);
    }
    table->num_cols++;
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s ", table->values[i]);
        }
        printf("\n");
    }
}

void free_table(Table *table) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        free(table->values[i]);
    }
    free(table->values);
    free(table);
}

void query_table(Table *table, int num_rows_per_query, int num_cols_per_query) {
    int i, j;
    for (i = 0; i < table->num_rows; i += num_rows_per_query) {
        for (j = 0; j < table->num_cols; j += num_cols_per_query) {
            printf("%s ", table->values[i + j / num_cols_per_query][j % num_cols_per_query]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table();
    add_row(table, "Name Age Gender");
    add_col(table, "John 25 M");
    add_col(table, "Jane 30 F");
    add_col(table, "Bob 20 M");
    add_row(table, "City Country");
    add_col(table, "New York USA");
    add_col(table, "Paris France");
    add_col(table, "Tokyo Japan");
    print_table(table);
    query_table(table, 1, 2);
    free_table(table);
    return 0;
}