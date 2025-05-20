//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *table_name;
    int num_rows;
    int num_cols;
    char **data;
} Table;

void create_table(Table *table, const char *name, int num_rows, int num_cols) {
    table->table_name = strdup(name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(sizeof(char) * num_cols);
    }
}

void insert_row(Table *table, int row_num, const char *data) {
    strcpy(table->data[row_num], data);
}

void delete_row(Table *table, int row_num) {
    free(table->data[row_num]);
    table->data[row_num] = NULL;
}

void update_row(Table *table, int row_num, const char *data) {
    strcpy(table->data[row_num], data);
}

void select_row(Table *table, int row_num, char *result) {
    strcpy(result, table->data[row_num]);
}

void select_all(Table *table, char *result) {
    for (int i = 0; i < table->num_rows; i++) {
        strcat(result, table->data[i]);
        strcat(result, "\n");
    }
}

int main() {
    Table my_table;
    create_table(&my_table, "my_table", 5, 3);
    insert_row(&my_table, 0, "John Doe");
    insert_row(&my_table, 1, "Jane Doe");
    insert_row(&my_table, 2, "Bob Smith");
    select_all(&my_table, "result.txt");
    printf("Table contents: \n%s", "result.txt");
    delete_row(&my_table, 1);
    update_row(&my_table, 0, "John Smith");
    select_row(&my_table, 0, "result.txt");
    printf("\nUpdated table contents: \n%s", "result.txt");
    return 0;
}