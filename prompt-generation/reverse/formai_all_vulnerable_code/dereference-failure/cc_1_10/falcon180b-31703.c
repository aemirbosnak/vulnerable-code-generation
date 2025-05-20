//Falcon-180B DATASET v1.0 Category: Database querying ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

// Define the structure of a table
typedef struct {
    char name[MAX_NAME_LEN];
    int num_rows;
    int num_cols;
    void **data;
} Table;

// Function to create a new table
Table *create_table(char *name, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    strncpy(table->name, name, MAX_NAME_LEN);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (void **)malloc(num_rows * sizeof(void *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (void *)malloc(num_cols * sizeof(char));
    }
    return table;
}

// Function to insert data into a table
void insert_data(Table *table, int row, int col, char *data) {
    strncpy((char *)table->data[row], data, MAX_NAME_LEN);
}

// Function to query data from a table
char *query_data(Table *table, int row, int col) {
    return (char *)table->data[row];
}

// Main function
int main() {
    // Create a new table
    Table *table = create_table("example_table", 3, 3);

    // Insert data into the table
    insert_data(table, 0, 0, "Name");
    insert_data(table, 0, 1, "Age");
    insert_data(table, 0, 2, "Gender");
    insert_data(table, 1, 0, "John");
    insert_data(table, 1, 1, "25");
    insert_data(table, 1, 2, "Male");
    insert_data(table, 2, 0, "Jane");
    insert_data(table, 2, 1, "30");
    insert_data(table, 2, 2, "Female");

    // Query data from the table
    char *name = query_data(table, 1, 0);
    char *age = query_data(table, 1, 1);
    char *gender = query_data(table, 1, 2);

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Gender: %s\n", gender);

    return 0;
}