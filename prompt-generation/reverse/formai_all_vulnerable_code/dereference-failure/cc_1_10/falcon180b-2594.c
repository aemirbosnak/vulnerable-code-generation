//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DATA_LEN 100

// Define the structure of a record
typedef struct {
    char name[MAX_NAME_LEN];
    char data[MAX_DATA_LEN];
} Record;

// Define the structure of a table
typedef struct {
    int num_records;
    Record *records;
} Table;

// Create a new table with the given number of records
Table *create_table(int num_records) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->num_records = num_records;
    table->records = (Record *) malloc(num_records * sizeof(Record));
    for (int i = 0; i < num_records; i++) {
        strcpy(table->records[i].name, "");
        strcpy(table->records[i].data, "");
    }
    return table;
}

// Add a new record to the table
void add_record(Table *table, char *name, char *data) {
    Record *record = (Record *) malloc(sizeof(Record));
    strcpy(record->name, name);
    strcpy(record->data, data);
    table->records[table->num_records - 1] = *record;
    free(record);
}

// Search for a record with the given name
Record *search_record(Table *table, char *name) {
    for (int i = 0; i < table->num_records; i++) {
        if (strcmp(table->records[i].name, name) == 0) {
            return &table->records[i];
        }
    }
    return NULL;
}

// Print the contents of the table
void print_table(Table *table) {
    for (int i = 0; i < table->num_records; i++) {
        printf("Name: %s\nData: %s\n\n", table->records[i].name, table->records[i].data);
    }
}

// Main function
int main() {
    // Create a new table with 3 records
    Table *table = create_table(3);

    // Add some records to the table
    add_record(table, "John", "1234");
    add_record(table, "Jane", "5678");
    add_record(table, "Bob", "9012");

    // Print the contents of the table
    print_table(table);

    // Search for a record with the name "John"
    Record *record = search_record(table, "John");
    if (record!= NULL) {
        printf("Found record with name %s:\n", record->name);
        printf("Data: %s\n", record->data);
    } else {
        printf("Record not found.\n");
    }

    // Free the memory used by the table
    free(table->records);
    free(table);

    return 0;
}