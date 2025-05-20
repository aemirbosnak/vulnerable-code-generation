//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 1000

typedef struct {
    char *data;
    int row;
    int col;
} Cell;

typedef struct {
    Cell *cells;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->cells = malloc(num_rows * num_cols * sizeof(Cell));
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            table->cells[i * num_cols + j].data = NULL;
            table->cells[i * num_cols + j].row = i;
            table->cells[i * num_cols + j].col = j;
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            if (table->cells[i * table->num_cols + j].data!= NULL) {
                free(table->cells[i * table->num_cols + j].data);
                table->cells[i * table->num_cols + j].data = NULL;
            }
        }
    }
    free(table->cells);
    free(table);
}

int set_cell_data(Table *table, int row, int col, char *data) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        table->cells[row * table->num_cols + col].data = strdup(data);
        return 1;
    }
    return 0;
}

char *get_cell_data(Table *table, int row, int col) {
    if (row >= 0 && row < table->num_rows && col >= 0 && col < table->num_cols) {
        return table->cells[row * table->num_cols + col].data;
    }
    return NULL;
}

int main() {
    Table *table = create_table(3, 3);
    set_cell_data(table, 0, 0, "Name");
    set_cell_data(table, 0, 1, "Age");
    set_cell_data(table, 0, 2, "City");
    set_cell_data(table, 1, 0, "John");
    set_cell_data(table, 1, 1, "25");
    set_cell_data(table, 1, 2, "New York");
    set_cell_data(table, 2, 0, "Jane");
    set_cell_data(table, 2, 1, "30");
    set_cell_data(table, 2, 2, "Los Angeles");
    destroy_table(table);
    return 0;
}