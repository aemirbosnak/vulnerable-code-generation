//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char *data;
    int row;
    int col;
} Cell;

typedef struct {
    Cell **table;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->table = (Cell**) calloc(num_rows, sizeof(Cell*));
    for (int i = 0; i < num_rows; i++) {
        table->table[i] = (Cell*) calloc(num_cols, sizeof(Cell));
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->table[i]);
    }
    free(table->table);
    free(table);
}

Cell *get_cell(Table *table, int row, int col) {
    return &table->table[row][col];
}

void set_cell(Table *table, int row, int col, const char *data) {
    Cell *cell = get_cell(table, row, col);
    cell->data = strdup(data);
    cell->row = row;
    cell->col = col;
}

const char *get_cell_data(Table *table, int row, int col) {
    Cell *cell = get_cell(table, row, col);
    return cell->data;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            Cell *cell = get_cell(table, i, j);
            printf("%-10s", cell->data);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    set_cell(table, 0, 0, "Name");
    set_cell(table, 0, 1, "Age");
    set_cell(table, 0, 2, "Email");
    set_cell(table, 1, 0, "John");
    set_cell(table, 1, 1, "30");
    set_cell(table, 1, 2, "john@example.com");
    set_cell(table, 2, 0, "Jane");
    set_cell(table, 2, 1, "25");
    set_cell(table, 2, 2, "jane@example.com");
    print_table(table);
    destroy_table(table);
    return 0;
}