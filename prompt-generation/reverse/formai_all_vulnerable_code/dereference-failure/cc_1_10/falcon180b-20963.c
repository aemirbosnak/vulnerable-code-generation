//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VAL_LEN 50

typedef struct {
    char **values;
    int num_cols;
    int num_rows;
} Table;

Table *create_table(int num_cols, int num_rows) {
    Table *table = malloc(sizeof(Table));
    table->values = malloc(num_cols * num_rows * sizeof(char *));
    table->num_cols = num_cols;
    table->num_rows = num_rows;

    for (int i = 0; i < num_cols * num_rows; i++) {
        table->values[i] = malloc(MAX_VAL_LEN * sizeof(char));
    }

    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_cols * table->num_rows; i++) {
        free(table->values[i]);
    }
    free(table->values);
    free(table);
}

void set_cell_value(Table *table, int row, int col, char *value) {
    strcpy(table->values[row * table->num_cols + col], value);
}

char *get_cell_value(Table *table, int row, int col) {
    return table->values[row * table->num_cols + col];
}

int main() {
    Table *table = create_table(3, 3);

    set_cell_value(table, 0, 0, "Name");
    set_cell_value(table, 0, 1, "Age");
    set_cell_value(table, 0, 2, "Gender");

    set_cell_value(table, 1, 0, "Alice");
    set_cell_value(table, 1, 1, "25");
    set_cell_value(table, 1, 2, "Female");

    set_cell_value(table, 2, 0, "Bob");
    set_cell_value(table, 2, 1, "30");
    set_cell_value(table, 2, 2, "Male");

    printf("Table:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s\t", get_cell_value(table, i, j));
        }
        printf("\n");
    }

    destroy_table(table);

    return 0;
}