//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char *name;
    int age;
    char *email;
} record_t;

typedef struct {
    char *name;
    int age;
    char *email;
} row_t;

typedef struct {
    row_t *rows;
    int num_rows;
    int num_cols;
} table_t;

table_t *create_table(int num_rows, int num_cols) {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->rows = (row_t *)malloc(num_rows * sizeof(row_t));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        table->rows[i].name = (char *)malloc(MAX_DATA * sizeof(char));
        table->rows[i].age = 0;
        table->rows[i].email = (char *)malloc(MAX_DATA * sizeof(char));
    }
    return table;
}

void destroy_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->rows[i].name);
        free(table->rows[i].email);
    }
    free(table->rows);
    free(table);
}

void print_table(table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("Name: %s\n", table->rows[i].name);
        printf("Age: %d\n", table->rows[i].age);
        printf("Email: %s\n", table->rows[i].email);
        printf("\n");
    }
}

int main() {
    table_t *table = create_table(3, 3);
    table->rows[0].name = "John";
    table->rows[0].age = 25;
    table->rows[0].email = "john@example.com";
    table->rows[1].name = "Jane";
    table->rows[1].age = 30;
    table->rows[1].email = "jane@example.com";
    table->rows[2].name = "Bob";
    table->rows[2].age = 40;
    table->rows[2].email = "bob@example.com";
    print_table(table);
    destroy_table(table);
    return 0;
}