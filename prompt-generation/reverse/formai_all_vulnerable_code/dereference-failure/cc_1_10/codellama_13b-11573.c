//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: sophisticated
/*
 * C Database Simulation Example Program
 *
 * This program simulates a database with a variety of data types and operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a database row
typedef struct {
    int id;
    char name[256];
    char email[256];
    char address[256];
    int age;
} Row;

// Define a structure for a database table
typedef struct {
    Row* rows;
    int num_rows;
} Table;

// Function to create a new database table
Table* create_table(int num_rows) {
    Table* table = malloc(sizeof(Table));
    table->rows = malloc(num_rows * sizeof(Row));
    table->num_rows = num_rows;
    return table;
}

// Function to insert a new row into a database table
void insert_row(Table* table, int id, char* name, char* email, char* address, int age) {
    int index = table->num_rows++;
    Row* row = &table->rows[index];
    row->id = id;
    strcpy(row->name, name);
    strcpy(row->email, email);
    strcpy(row->address, address);
    row->age = age;
}

// Function to update a row in a database table
void update_row(Table* table, int id, char* name, char* email, char* address, int age) {
    for (int i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        if (row->id == id) {
            strcpy(row->name, name);
            strcpy(row->email, email);
            strcpy(row->address, address);
            row->age = age;
            break;
        }
    }
}

// Function to delete a row from a database table
void delete_row(Table* table, int id) {
    for (int i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        if (row->id == id) {
            for (int j = i; j < table->num_rows - 1; j++) {
                table->rows[j] = table->rows[j + 1];
            }
            table->num_rows--;
            break;
        }
    }
}

// Function to query a row in a database table
Row* query_row(Table* table, int id) {
    for (int i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        if (row->id == id) {
            return row;
        }
    }
    return NULL;
}

// Function to print a row in a database table
void print_row(Row* row) {
    printf("%d\t%s\t%s\t%s\t%d\n", row->id, row->name, row->email, row->address, row->age);
}

// Function to print all rows in a database table
void print_table(Table* table) {
    for (int i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        print_row(row);
    }
}

int main() {
    // Create a new database table with 100 rows
    Table* table = create_table(100);

    // Insert some data into the table
    insert_row(table, 1, "John", "john@example.com", "123 Main St", 25);
    insert_row(table, 2, "Jane", "jane@example.com", "456 Elm St", 30);
    insert_row(table, 3, "Bob", "bob@example.com", "789 Oak St", 35);

    // Update a row in the table
    update_row(table, 2, "Jane Doe", "jane@example.com", "456 Elm St", 31);

    // Delete a row from the table
    delete_row(table, 1);

    // Query a row from the table
    Row* row = query_row(table, 2);
    print_row(row);

    // Print all rows in the table
    print_table(table);

    // Free the memory used by the table
    free(table->rows);
    free(table);

    return 0;
}