//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 100
#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LENGTH 100

typedef struct {
    char *table_name;
    int num_rows;
    int num_cols;
    char **data;
} table_t;

table_t *create_table(char *name, int rows, int cols) {
    table_t *table = malloc(sizeof(table_t));
    table->table_name = strdup(name);
    table->num_rows = rows;
    table->num_cols = cols;
    table->data = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        table->data[i] = malloc(cols * sizeof(char));
        memset(table->data[i], 0, cols);
    }
    return table;
}

void delete_table(table_t *table) {
    free(table->table_name);
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(table_t *table) {
    printf("Table: %s\n", table->table_name);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    table_t *table1 = create_table("table1", 3, 3);
    strcpy(table1->data[0], "1");
    strcpy(table1->data[1], "2");
    strcpy(table1->data[2], "3");

    table_t *table2 = create_table("table2", 2, 2);
    strcpy(table2->data[0], "a");
    strcpy(table2->data[1], "b");

    print_table(table1);
    print_table(table2);

    delete_table(table1);
    delete_table(table2);

    return 0;
}