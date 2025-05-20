//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_VALUE_LENGTH 256
#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Row;

typedef struct {
    int num_rows;
    int num_columns;
    Row *data;
} Table;

Table *create_table(int num_rows, int num_columns) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (Row *) malloc(sizeof(Row) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        strcpy(table->data[i].name, "");
        strcpy(table->data[i].value, "");
    }
    return table;
}

void destroy_table(Table *table) {
    free(table->data);
    free(table);
}

void set_cell_value(Table *table, int row, int col, char *value) {
    strcpy(table->data[row].value, value);
}

char *get_cell_value(Table *table, int row, int col) {
    return table->data[row].value;
}

int main() {
    Table *table = create_table(5, 5);

    set_cell_value(table, 0, 0, "Name1");
    set_cell_value(table, 0, 1, "Value1");
    set_cell_value(table, 1, 0, "Name2");
    set_cell_value(table, 1, 1, "Value2");
    set_cell_value(table, 2, 0, "Name3");
    set_cell_value(table, 2, 1, "Value3");
    set_cell_value(table, 3, 0, "Name4");
    set_cell_value(table, 3, 1, "Value4");
    set_cell_value(table, 4, 0, "Name5");
    set_cell_value(table, 4, 1, "Value5");

    char *value1 = get_cell_value(table, 0, 1);
    printf("%s\n", value1);

    destroy_table(table);
    return 0;
}