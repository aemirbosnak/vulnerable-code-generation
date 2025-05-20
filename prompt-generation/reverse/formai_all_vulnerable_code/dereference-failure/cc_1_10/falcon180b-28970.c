//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_LEN 1000

typedef struct {
    char *data;
    int row_num;
    int col_num;
} Cell;

typedef struct {
    int num_rows;
    int num_cols;
    Cell **data;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table*) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Cell**) malloc(sizeof(Cell*) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (Cell*) malloc(sizeof(Cell) * num_cols);
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j].data = NULL;
            table->data[i][j].row_num = i;
            table->data[i][j].col_num = j;
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

void set_cell_data(Table *table, int row_num, int col_num, char *data) {
    table->data[row_num][col_num].data = strdup(data);
}

char *get_cell_data(Table *table, int row_num, int col_num) {
    return table->data[row_num][col_num].data;
}

int main() {
    Table *table = create_table(10, 10);
    set_cell_data(table, 0, 0, "Hello");
    set_cell_data(table, 1, 1, "World");
    char *data = get_cell_data(table, 0, 0);
    printf("%s\n", data);
    destroy_table(table);
    return 0;
}