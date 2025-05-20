//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Cell;

typedef struct {
    int rows;
    int cols;
    Cell **data;
} Table;

Table *create_table(int rows, int cols) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->rows = rows;
    table->cols = cols;
    table->data = (Cell **) malloc(rows * sizeof(Cell *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = (Cell *) malloc(cols * sizeof(Cell));
        for (int j = 0; j < cols; j++) {
            strcpy(table->data[i][j].name, "");
            strcpy(table->data[i][j].value, "");
        }
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            free(table->data[i][j].name);
            free(table->data[i][j].value);
        }
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s = %s\n", table->data[i][j].name, table->data[i][j].value);
        }
    }
}

int main() {
    Table *table = create_table(2, 3);

    strcpy(table->data[0][0].name, "Name");
    strcpy(table->data[0][0].value, "John");
    strcpy(table->data[0][1].name, "Age");
    strcpy(table->data[0][1].value, "30");
    strcpy(table->data[0][2].name, "Gender");
    strcpy(table->data[0][2].value, "Male");

    strcpy(table->data[1][0].name, "Name");
    strcpy(table->data[1][0].value, "Jane");
    strcpy(table->data[1][1].name, "Age");
    strcpy(table->data[1][1].value, "25");
    strcpy(table->data[1][2].name, "Gender");
    strcpy(table->data[1][2].value, "Female");

    print_table(table);

    destroy_table(table);

    return 0;
}