//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_STR_LEN 100

struct record {
    char *data;
    int row;
    int col;
};

struct table {
    struct record *records;
    int num_rows;
    int num_cols;
};

struct table *create_table(int num_rows, int num_cols) {
    struct table *table = malloc(sizeof(struct table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->records = malloc(sizeof(struct record) * num_rows * num_cols);
    for (int i = 0; i < num_rows * num_cols; i++) {
        table->records[i].data = malloc(MAX_STR_LEN * sizeof(char));
    }
    return table;
}

void destroy_table(struct table *table) {
    for (int i = 0; i < table->num_rows * table->num_cols; i++) {
        free(table->records[i].data);
    }
    free(table->records);
    free(table);
}

void set_cell_value(struct table *table, int row, int col, char *value) {
    table->records[row * table->num_cols + col].data = strdup(value);
}

char *get_cell_value(struct table *table, int row, int col) {
    return table->records[row * table->num_cols + col].data;
}

int main() {
    struct table *table = create_table(3, 3);
    set_cell_value(table, 0, 0, "Name");
    set_cell_value(table, 0, 1, "Age");
    set_cell_value(table, 0, 2, "Gender");
    set_cell_value(table, 1, 0, "John");
    set_cell_value(table, 1, 1, "25");
    set_cell_value(table, 1, 2, "Male");
    set_cell_value(table, 2, 0, "Jane");
    set_cell_value(table, 2, 1, "30");
    set_cell_value(table, 2, 2, "Female");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%s ", get_cell_value(table, i, j));
        }
        printf("\n");
    }
    destroy_table(table);
    return 0;
}