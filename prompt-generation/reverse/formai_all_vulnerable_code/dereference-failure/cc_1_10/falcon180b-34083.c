//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100
#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Cell;

typedef struct {
    int num_rows;
    int num_cols;
    Cell data[MAX_ROWS][MAX_COLS];
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j].name[0] = '\0';
            table->data[i][j].value[0] = '\0';
        }
    }
    return table;
}

void destroy_table(Table *table) {
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s = %s\n", table->data[i][j].name, table->data[i][j].value);
        }
    }
}

int main() {
    Table *table = create_table(2, 2);

    strcpy(table->data[0][0].name, "name");
    strcpy(table->data[0][0].value, "John");
    strcpy(table->data[0][1].name, "age");
    strcpy(table->data[0][1].value, "30");

    strcpy(table->data[1][0].name, "name");
    strcpy(table->data[1][0].value, "Jane");
    strcpy(table->data[1][1].name, "age");
    strcpy(table->data[1][1].value, "25");

    print_table(table);
    destroy_table(table);

    return 0;
}