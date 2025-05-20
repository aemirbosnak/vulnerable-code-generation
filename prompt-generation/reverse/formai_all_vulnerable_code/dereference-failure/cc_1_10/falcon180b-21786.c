//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_SIZE 1024

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

Table *create_table(int rows, int cols) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(rows * cols * MAX_SIZE);
    table->rows = rows;
    table->cols = cols;
    return table;
}

void free_table(Table *table) {
    free(table->data);
    free(table);
}

int get_cell(Table *table, int row, int col) {
    int index = row * table->cols + col;
    return *(int *) (table->data + index * MAX_SIZE);
}

void set_cell(Table *table, int row, int col, int value) {
    int index = row * table->cols + col;
    *(int *) (table->data + index * MAX_SIZE) = value;
}

int main() {
    Table *table = create_table(3, 3);
    set_cell(table, 0, 0, 1);
    set_cell(table, 0, 1, 2);
    set_cell(table, 0, 2, 3);
    set_cell(table, 1, 0, 4);
    set_cell(table, 1, 1, 5);
    set_cell(table, 1, 2, 6);
    set_cell(table, 2, 0, 7);
    set_cell(table, 2, 1, 8);
    set_cell(table, 2, 2, 9);

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += get_cell(table, i, j);
        }
    }

    printf("Sum: %d\n", sum);

    free_table(table);

    return 0;
}