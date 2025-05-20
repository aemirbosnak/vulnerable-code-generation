//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

// Define the structure for a database table
typedef struct {
    char *table_name;
    int num_rows;
    int num_columns;
    char **data;
} Table;

// Function to create a new database table
Table *create_table(char *table_name, int num_rows, int num_columns) {
    Table *new_table = (Table *)malloc(sizeof(Table));
    new_table->table_name = table_name;
    new_table->num_rows = num_rows;
    new_table->num_columns = num_columns;
    new_table->data = (char **)malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        new_table->data[i] = (char *)malloc(sizeof(char) * num_columns);
        memset(new_table->data[i], '\0', num_columns);
    }
    return new_table;
}

// Function to insert data into a database table
void insert_data(Table *table, int row, int col, char *data) {
    strncat(table->data[row], data, table->num_columns - col);
}

// Function to print a database table
void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new database table
    Table *my_table = create_table("my_table", 3, 3);
    strcpy(my_table->table_name, "my_table");

    // Insert data into the table
    insert_data(my_table, 0, 0, "Name");
    insert_data(my_table, 0, 1, "Age");
    insert_data(my_table, 0, 2, "Gender");
    insert_data(my_table, 1, 0, "John");
    insert_data(my_table, 1, 1, "25");
    insert_data(my_table, 1, 2, "Male");
    insert_data(my_table, 2, 0, "Jane");
    insert_data(my_table, 2, 1, "30");
    insert_data(my_table, 2, 2, "Female");

    // Print the database table
    print_table(my_table);

    return 0;
}