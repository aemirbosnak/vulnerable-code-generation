//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
    char *data;
} Cell;

typedef struct {
    int num_rows;
    int num_cols;
    Cell **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Cell **) malloc(num_rows * sizeof(Cell *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (Cell *) malloc(num_cols * sizeof(Cell));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j].row = i;
            table->data[i][j].col = j;
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%d:%s\t", table->data[i][j].row, table->data[i][j].data);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    table->data[0][0].data = "Name";
    table->data[0][1].data = "Age";
    table->data[0][2].data = "Gender";

    table->data[1][0].data = "John";
    table->data[1][1].data = "25";
    table->data[1][2].data = "Male";

    table->data[2][0].data = "Jane";
    table->data[2][1].data = "30";
    table->data[2][2].data = "Female";

    print_table(table);

    destroy_table(table);
    return 0;
}