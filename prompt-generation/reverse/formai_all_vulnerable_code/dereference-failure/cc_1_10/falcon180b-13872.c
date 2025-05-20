//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char *data[MAX_COLS];
    int row_count;
    int col_count;
} Table;

Table *create_table(int rows, int cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->row_count = rows;
    table->col_count = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table->data[j] = (char *)malloc(MAX_DATA);
            strcpy(table->data[j], "");
        }
    }
    return table;
}

void insert_data(Table *table, int row, int col, char *data) {
    strcpy(table->data[col], data);
}

void print_table(Table *table) {
    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            printf("%s ", table->data[j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
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

    return 0;
}