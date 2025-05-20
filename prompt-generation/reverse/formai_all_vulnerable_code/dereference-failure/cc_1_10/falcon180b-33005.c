//Falcon-180B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LENGTH 1000

typedef struct {
    char data[MAX_DATA_LENGTH];
    int row;
    int col;
} cell;

typedef struct {
    int num_rows;
    int num_cols;
    cell **data;
} spreadsheet;

spreadsheet *create_spreadsheet(int num_rows, int num_cols) {
    spreadsheet *ss = (spreadsheet *)malloc(sizeof(spreadsheet));
    ss->num_rows = num_rows;
    ss->num_cols = num_cols;
    ss->data = (cell **)malloc(num_rows * sizeof(cell *));
    for (int i = 0; i < num_rows; i++) {
        ss->data[i] = (cell *)malloc(num_cols * sizeof(cell));
    }
    return ss;
}

void destroy_spreadsheet(spreadsheet *ss) {
    for (int i = 0; i < ss->num_rows; i++) {
        free(ss->data[i]);
    }
    free(ss->data);
    free(ss);
}

void set_cell_value(spreadsheet *ss, int row, int col, char *value) {
    strcpy(ss->data[row][col].data, value);
}

char *get_cell_value(spreadsheet *ss, int row, int col) {
    return ss->data[row][col].data;
}

int main() {
    spreadsheet *ss = create_spreadsheet(3, 3);
    set_cell_value(ss, 0, 0, "Hello");
    set_cell_value(ss, 0, 1, "World");
    set_cell_value(ss, 1, 0, "Foo");
    set_cell_value(ss, 1, 1, "Bar");
    set_cell_value(ss, 2, 0, "Baz");
    set_cell_value(ss, 2, 1, "Quux");
    char *value = get_cell_value(ss, 1, 1);
    printf("%s\n", value);
    destroy_spreadsheet(ss);
    return 0;
}