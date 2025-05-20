//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char data[MAX_DATA_LEN];
    int row;
    int col;
} Cell;

typedef struct {
    Cell *data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Cell *)malloc(sizeof(Cell) * num_rows * num_cols);
    return table;
}

void destroy_table(Table *table) {
    free(table->data);
    free(table);
}

void set_cell_data(Cell *cell, char *data) {
    strncpy(cell->data, data, MAX_DATA_LEN);
}

char *get_cell_data(Cell *cell) {
    return cell->data;
}

void set_cell_row_col(Cell *cell, int row, int col) {
    cell->row = row;
    cell->col = col;
}

int get_cell_row(Cell *cell) {
    return cell->row;
}

int get_cell_col(Cell *cell) {
    return cell->col;
}

int main() {
    Table *table = create_table(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            Cell *cell = &table->data[i * 5 + j];
            set_cell_data(cell, "Cell ");
            set_cell_row_col(cell, i, j);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            Cell *cell = &table->data[i * 5 + j];
            printf("Row: %d, Col: %d, Data: %s\n", get_cell_row(cell), get_cell_col(cell), get_cell_data(cell));
        }
    }
    destroy_table(table);
    return 0;
}