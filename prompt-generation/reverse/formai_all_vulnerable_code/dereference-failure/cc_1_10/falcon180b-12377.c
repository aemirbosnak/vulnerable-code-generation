//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 100

// Define the structure of a database table
typedef struct {
    char name[MAX_NAME_LEN];
    int num_rows;
    int num_cols;
    int **data;
} Table;

// Function to create a new table with given dimensions and name
Table* create_table(int num_rows, int num_cols, char* name) {
    Table* table = (Table*)malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (int**)malloc(num_rows * sizeof(int*));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (int*)malloc(num_cols * sizeof(int));
    }
    return table;
}

// Function to insert data into a table at a specified position
void insert_data(Table* table, int row, int col, int data) {
    table->data[row][col] = data;
}

// Function to retrieve data from a table at a specified position
int get_data(Table* table, int row, int col) {
    return table->data[row][col];
}

// Function to print the contents of a table
void print_table(Table* table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%d ", get_data(table, i, j));
        }
        printf("\n");
    }
}

int main() {
    // Create a new table with 3 rows and 4 columns
    Table* table = create_table(3, 4, "My Table");

    // Insert some data into the table
    insert_data(table, 0, 0, 1);
    insert_data(table, 0, 1, 2);
    insert_data(table, 0, 2, 3);
    insert_data(table, 1, 0, 4);
    insert_data(table, 1, 1, 5);
    insert_data(table, 1, 2, 6);
    insert_data(table, 2, 0, 7);
    insert_data(table, 2, 1, 8);
    insert_data(table, 2, 2, 9);

    // Print the contents of the table
    print_table(table);

    return 0;
}