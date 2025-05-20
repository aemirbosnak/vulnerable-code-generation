//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rows;
    int cols;
    int **data;
} Table;

void create_table(Table *table, char *name, int rows, int cols) {
    strcpy(table->name, name);
    table->rows = rows;
    table->cols = cols;
    table->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            table->data[i][j] = 0;
        }
    }
}

void insert_row(Table *table, int row, int *data) {
    for (int i = 0; i < table->cols; i++) {
        table->data[row][i] = data[i];
    }
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table, "example", 3, 3);
    insert_row(&table, 0, (int []){1, 2, 3});
    insert_row(&table, 1, (int []){4, 5, 6});
    insert_row(&table, 2, (int []){7, 8, 9});
    print_table(&table);
    return 0;
}