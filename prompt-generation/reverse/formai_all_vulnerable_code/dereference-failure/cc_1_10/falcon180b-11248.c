//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *data;
    int row;
    int col;
} Cell;

typedef struct {
    Cell **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = malloc(num_rows * sizeof(Cell *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(num_cols * sizeof(Cell));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j].data = NULL;
            table->data[i][j].row = i;
            table->data[i][j].col = j;
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            if (table->data[i][j].data!= NULL) {
                free(table->data[i][j].data);
            }
        }
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void set_cell_value(Table *table, int row, int col, char *value) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        table->data[row][col].data = strdup(value);
    }
}

char *get_cell_value(Table *table, int row, int col) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        return table->data[row][col].data;
    }
    return NULL;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%-10s", get_cell_value(table, i, j));
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    set_cell_value(table, 0, 0, "Name");
    set_cell_value(table, 0, 1, "Age");
    set_cell_value(table, 0, 2, "Gender");
    set_cell_value(table, 1, 0, "John");
    set_cell_value(table, 1, 1, "25");
    set_cell_value(table, 1, 2, "Male");
    set_cell_value(table, 2, 0, "Jane");
    set_cell_value(table, 2, 1, "30");
    set_cell_value(table, 2, 2, "Female");
    print_table(table);
    destroy_table(table);
    return 0;
}