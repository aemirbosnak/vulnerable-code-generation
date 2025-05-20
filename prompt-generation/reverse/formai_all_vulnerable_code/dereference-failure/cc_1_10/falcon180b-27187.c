//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *name;
    int num_rows;
    int num_columns;
    char **data;
} Table;

Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = (Table*)malloc(sizeof(Table));
    table->name = strdup(name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (char**)malloc(num_rows * sizeof(char*));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char*)malloc(num_columns * MAX_FIELD_SIZE);
        memset(table->data[i], 0, num_columns * MAX_FIELD_SIZE);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int add_row(Table *table, char *row_data) {
    int row_index = table->num_rows;
    table->num_rows++;
    table->data[row_index] = strdup(row_data);
    return row_index;
}

char *get_cell_value(Table *table, int row, int column) {
    return table->data[row][column];
}

int main() {
    Table *table = create_table("my_table", 2, 3);
    add_row(table, "1 2 3");
    add_row(table, "4 5 6");
    printf("%s\n", get_cell_value(table, 0, 0)); // prints "1"
    printf("%s\n", get_cell_value(table, 1, 2)); // prints "6"
    destroy_table(table);
    return 0;
}