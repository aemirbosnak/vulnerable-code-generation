//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *table_name;
    int num_rows;
    int num_cols;
    char **row_data;
} Table;

Table *create_table(char *table_name, int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->table_name = table_name;
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->row_data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->row_data[i] = malloc(sizeof(char) * MAX_DATA_SIZE);
    }
    return table;
}

void add_row(Table *table, char *row_data) {
    strcpy(table->row_data[table->num_rows - 1], row_data);
}

void print_table(Table *table) {
    printf("Table: %s\n", table->table_name);
    printf("Columns: %d\n", table->num_cols);
    printf("Rows: %d\n", table->num_rows);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->row_data[i]);
        }
        printf("\n");
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->row_data[i]);
    }
    free(table->row_data);
    free(table);
}

int main() {
    Table *table = create_table("Ada Lovelace", 2, 3);
    add_row(table, "Augusta Ada King-Noel");
    add_row(table, "1815-1852");
    print_table(table);
    free_table(table);
    return 0;
}