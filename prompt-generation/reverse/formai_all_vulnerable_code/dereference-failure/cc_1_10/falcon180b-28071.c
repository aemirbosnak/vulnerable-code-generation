//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 1000

// Define the structure of a row
typedef struct {
    int row_id;
    char data[MAX_DATA_LEN];
} Row;

// Define the structure of a table
typedef struct {
    int num_rows;
    int num_cols;
    Row *rows;
} Table;

// Function to initialize a table
Table *init_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->rows = (Row *)malloc(sizeof(Row) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->rows[i].row_id = i;
    }
    return table;
}

// Function to insert a row into a table
void insert_row(Table *table, int row_id, char *data) {
    if (row_id >= table->num_rows) {
        printf("Error: row_id out of range.\n");
        return;
    }
    strcpy(table->rows[row_id].data, data);
}

// Function to delete a row from a table
void delete_row(Table *table, int row_id) {
    if (row_id >= table->num_rows) {
        printf("Error: row_id out of range.\n");
        return;
    }
    for (int i = row_id; i < table->num_rows - 1; i++) {
        table->rows[i] = table->rows[i + 1];
    }
    table->num_rows--;
}

// Function to update a row in a table
void update_row(Table *table, int row_id, char *data) {
    if (row_id >= table->num_rows) {
        printf("Error: row_id out of range.\n");
        return;
    }
    strcpy(table->rows[row_id].data, data);
}

// Function to retrieve a row from a table
Row *get_row(Table *table, int row_id) {
    if (row_id >= table->num_rows) {
        printf("Error: row_id out of range.\n");
        return NULL;
    }
    return &table->rows[row_id];
}

// Function to retrieve all rows from a table
void get_all_rows(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("Row ID: %d, Data: %s\n", table->rows[i].row_id, table->rows[i].data);
    }
}

int main() {
    Table *table = init_table(5, 2);
    insert_row(table, 0, "John");
    insert_row(table, 1, "Doe");
    insert_row(table, 2, "Jane");
    insert_row(table, 3, "Doe");
    insert_row(table, 4, "Jane");
    get_all_rows(table);
    delete_row(table, 3);
    get_all_rows(table);
    update_row(table, 0, "John Smith");
    get_all_rows(table);
    return 0;
}