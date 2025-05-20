//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VALUES 10000

typedef struct {
    int row;
    int col;
    char value[MAX_VALUES];
} cell_t;

typedef struct {
    int num_rows;
    int num_cols;
    cell_t *data;
} table_t;

table_t *create_table(int num_rows, int num_cols) {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    if (table == NULL) {
        printf("Error: could not allocate memory for table.\n");
        exit(1);
    }
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (cell_t *)malloc(sizeof(cell_t) * num_rows * num_cols);
    if (table->data == NULL) {
        printf("Error: could not allocate memory for table data.\n");
        exit(1);
    }
    for (int i = 0; i < num_rows * num_cols; i++) {
        table->data[i].row = -1;
        table->data[i].col = -1;
        strcpy(table->data[i].value, "");
    }
    return table;
}

void destroy_table(table_t *table) {
    free(table->data);
    free(table);
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i * table->num_cols + j].value);
        }
        printf("\n");
    }
}

int main() {
    table_t *table = create_table(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table->data[i * 10 + j].row = i;
            table->data[i * 10 + j].col = j;
            sprintf(table->data[i * 10 + j].value, "%.2f", (float)i * j / 10);
        }
    }
    print_table(table);
    destroy_table(table);
    return 0;
}