//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    Cell *cells;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->cells = (Cell *)malloc(num_rows * num_cols * sizeof(Cell));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            table->cells[i * num_cols + j].row = i;
            table->cells[i * num_cols + j].col = j;
        }
    }
    return table;
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%d ", table->cells[i * table->num_cols + j].row * table->num_cols + table->cells[i * table->num_cols + j].col);
        }
        printf("\n");
    }
}

void destroy_table(Table *table) {
    free(table->cells);
    free(table);
}

int main() {
    Table *table = create_table(MAX_ROWS, MAX_COLS);
    print_table(table);
    destroy_table(table);
    return 0;
}