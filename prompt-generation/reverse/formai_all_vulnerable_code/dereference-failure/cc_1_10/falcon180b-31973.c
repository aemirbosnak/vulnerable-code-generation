//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int rows;
    int cols;
    char **data;
} Table;

void create_table(Table *table, char *name, int rows, int cols) {
    table->name = name;
    table->rows = rows;
    table->cols = cols;
    table->data = malloc(rows * cols * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        table->data[i] = malloc(cols * MAX_DATA_SIZE);
        for (int j = 0; j < cols; j++) {
            table->data[i][j] = malloc(MAX_DATA_SIZE);
        }
    }
}

void insert_data(Table *table, int row, int col, char *data) {
    strcpy(table->data[row][col], data);
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Rows: %d\n", table->rows);
    printf("Cols: %d\n", table->cols);
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s\t", table->data[i][j]);
        }
        printf("\n");
    }
}

void delete_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            free(table->data[i][j]);
        }
        free(table->data[i]);
    }
    free(table->data);
    free(table->name);
    free(table);
}

int main() {
    Table *table = malloc(sizeof(Table));
    create_table(table, "example_table", 3, 3);
    insert_data(table, 0, 0, "Name");
    insert_data(table, 0, 1, "Age");
    insert_data(table, 0, 2, "Gender");
    insert_data(table, 1, 0, "John");
    insert_data(table, 1, 1, "25");
    insert_data(table, 1, 2, "Male");
    insert_data(table, 2, 0, "Jane");
    insert_data(table, 2, 1, "30");
    insert_data(table, 2, 2, "Female");
    print_table(table);
    delete_table(table);
    return 0;
}