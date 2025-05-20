//Falcon-180B DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *row_name;
    int col_count;
    int **data;
} Table;

Table *create_table(char *name) {
    Table *table = malloc(sizeof(Table));
    table->row_name = strdup(name);
    table->col_count = 0;
    table->data = NULL;
    return table;
}

void add_column(Table *table, char *name) {
    table->col_count++;
    table->data = realloc(table->data, sizeof(int *) * table->col_count);
    table->data[table->col_count - 1] = NULL;
}

void set_cell(Table *table, int row, int col, int value) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        table->data[col][row] = value;
    } else {
        printf("Error: Invalid cell coordinates\n");
    }
}

int get_cell(Table *table, int row, int col) {
    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
        return table->data[col][row];
    } else {
        printf("Error: Invalid cell coordinates\n");
        return -1;
    }
}

void print_table(Table *table) {
    int i, j;
    for (i = 0; i < table->col_count; i++) {
        printf("%s ", table->data[i]? table->data[i][0] : "");
    }
    printf("\n");
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < table->col_count; j++) {
            printf("%d ", get_cell(table, i, j));
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("example");
    add_column(table, "name");
    add_column(table, "age");
    set_cell(table, 0, 0, "John");
    set_cell(table, 0, 1, 25);
    set_cell(table, 1, 0, "Jane");
    set_cell(table, 1, 1, 30);
    print_table(table);
    return 0;
}