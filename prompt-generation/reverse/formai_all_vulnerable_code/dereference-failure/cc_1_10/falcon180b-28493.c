//Falcon-180B DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Cell;

typedef struct {
    int num_rows;
    int num_cols;
    Cell cells[MAX_ROWS][MAX_COLS];
} Table;

Table* create_table(int num_rows, int num_cols) {
    Table* table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            table->cells[i][j].name[0] = '\0';
            table->cells[i][j].value[0] = '\0';
        }
    }
    return table;
}

void set_cell_value(Table* table, int row, int col, char* name, char* value) {
    strcpy(table->cells[row][col].name, name);
    strcpy(table->cells[row][col].value, value);
}

char* get_cell_value(Table* table, int row, int col, char* name) {
    for (int i = 0; i < table->num_cols; i++) {
        if (strcmp(table->cells[row][i].name, name) == 0) {
            return table->cells[row][i].value;
        }
    }
    return NULL;
}

int main() {
    Table* table = create_table(2, 3);

    set_cell_value(table, 0, 0, "Name", "Alice");
    set_cell_value(table, 0, 1, "Age", "25");
    set_cell_value(table, 0, 2, "City", "New York");

    set_cell_value(table, 1, 0, "Name", "Bob");
    set_cell_value(table, 1, 1, "Age", "30");
    set_cell_value(table, 1, 2, "City", "San Francisco");

    char* value = get_cell_value(table, 1, 1, "Age");
    printf("%s\n", value);

    return 0;
}