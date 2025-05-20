//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_SIZE 100

// Define the structure of a table
typedef struct {
    char name[MAX_SIZE];
    int num_rows;
    int num_cols;
    int **data;
} Table;

// Function to create a new table
Table *create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (int **)malloc(num_rows * sizeof(int *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (int *)malloc(num_cols * sizeof(int));
    }
    return table;
}

// Function to insert a value into a table
void insert_value(Table *table, int row, int col, int value) {
    table->data[row][col] = value;
}

// Function to print a table
void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Number of rows: %d\n", table->num_rows);
    printf("Number of columns: %d\n", table->num_cols);
    printf("-----------------\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%d ", table->data[i][j]);
        }
        printf("\n");
    }
}

// Function to delete a table
void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int main() {
    // Create a new table
    Table *table = create_table("Example Table", 3, 3);

    // Insert values into the table
    insert_value(table, 0, 0, 1);
    insert_value(table, 0, 1, 2);
    insert_value(table, 0, 2, 3);
    insert_value(table, 1, 0, 4);
    insert_value(table, 1, 1, 5);
    insert_value(table, 1, 2, 6);
    insert_value(table, 2, 0, 7);
    insert_value(table, 2, 1, 8);
    insert_value(table, 2, 2, 9);

    // Print the table
    print_table(table);

    // Delete the table
    delete_table(table);

    return 0;
}