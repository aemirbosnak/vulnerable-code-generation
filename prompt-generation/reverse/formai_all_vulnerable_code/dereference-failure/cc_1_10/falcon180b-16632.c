//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a record in the database
typedef struct {
    int id;
    char *name;
    int age;
} Record;

// Define the structure of a table in the database
typedef struct {
    int size;
    int capacity;
    Record *records;
} Table;

// Initialize a new table with the given capacity
Table *new_table(int capacity) {
    Table *table = malloc(sizeof(Table));
    table->size = 0;
    table->capacity = capacity;
    table->records = malloc(capacity * sizeof(Record));
    return table;
}

// Add a new record to the table
void add_record(Table *table, int id, char *name, int age) {
    if (table->size >= table->capacity) {
        printf("Error: Table is full!\n");
        return;
    }
    table->records[table->size] = (Record) {
       .id = id,
       .name = name,
       .age = age
    };
    table->size++;
}

// Print all records in the table
void print_records(Table *table) {
    for (int i = 0; i < table->size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", table->records[i].id, table->records[i].name, table->records[i].age);
    }
}

// Main function to simulate the database operations
int main() {
    // Initialize a new table with capacity of 10 records
    Table *db = new_table(10);

    // Add some records to the table
    add_record(db, 1, "Alice", 25);
    add_record(db, 2, "Bob", 30);
    add_record(db, 3, "Charlie", 20);

    // Print all records in the table
    print_records(db);

    // Try to add more records to the full table
    add_record(db, 4, "David", 28);

    // Print all records in the table again
    print_records(db);

    // Free the memory allocated for the table and records
    free(db->records);
    free(db);

    return 0;
}