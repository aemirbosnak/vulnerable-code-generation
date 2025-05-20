//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_DATA_SIZE 1000

// Structure to store the database table information
typedef struct table {
    char name[MAX_DATA_SIZE];
    int num_rows;
    int num_columns;
    char **data;
} Table;

// Function to create a new database table
Table *create_table(char *name, int num_rows, int num_columns) {
    Table *table = (Table *)malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_columns = num_columns;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_columns * sizeof(char));
    }
    return table;
}

// Function to add data to the database table
void add_data(Table *table, int row, int col, char *data) {
    strcpy(table->data[row - 1] + (col - 1) * MAX_DATA_SIZE, data);
}

// Function to print the database table
void print_table(Table *table) {
    printf("Table Name: %s\n", table->name);
    printf("Number of Rows: %d\n", table->num_rows);
    printf("Number of Columns: %d\n", table->num_columns);
    printf("Data:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

// Function to delete a database table
void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

// Main function to test the database operations
int main() {
    Table *table = create_table("Test Table", 3, 3);
    add_data(table, 1, 1, "John");
    add_data(table, 1, 2, "Doe");
    add_data(table, 2, 1, "Jane");
    add_data(table, 2, 2, "Doe");
    add_data(table, 3, 1, "Bob");
    add_data(table, 3, 2, "Smith");
    print_table(table);
    delete_table(table);
    return 0;
}