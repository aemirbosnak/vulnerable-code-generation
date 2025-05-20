//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

void create_table(Table *table, int num_rows, int num_cols) {
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * sizeof(char));
        for (int j = 0; j < num_cols; j++) {
            table->data[i][j] = '\0';
        }
    }
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    create_table(&table, 3, 3);

    strcpy(table.data[0][0], "Name");
    strcpy(table.data[0][1], "Age");
    strcpy(table.data[0][2], "Salary");

    strcpy(table.data[1][0], "John");
    table.data[1][1] = (char *)malloc(10 * sizeof(char));
    sprintf(table.data[1][1], "%d", 25);
    strcpy(table.data[1][2], "5000.50");

    strcpy(table.data[2][0], "Jane");
    table.data[2][1] = (char *)malloc(10 * sizeof(char));
    sprintf(table.data[2][1], "%d", 30);
    strcpy(table.data[2][2], "7000.75");

    print_table(&table);

    destroy_table(&table);

    return 0;
}