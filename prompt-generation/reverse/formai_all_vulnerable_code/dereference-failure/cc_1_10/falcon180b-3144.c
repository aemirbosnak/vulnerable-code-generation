//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields per record
#define MAX_FIELDS 10

// Define the structure for a field
typedef struct {
    char name[50];
    int type;
    int size;
} field_t;

// Define the structure for a record
typedef struct {
    int num_fields;
    field_t fields[MAX_FIELDS];
} record_t;

// Define the structure for a table
typedef struct {
    char name[50];
    int num_records;
    record_t records[100];
} table_t;

// Function to create a new table
table_t* create_table(char* name) {
    table_t* table = (table_t*)malloc(sizeof(table_t));
    strcpy(table->name, name);
    table->num_records = 0;
    return table;
}

// Function to add a record to a table
void add_record(table_t* table, record_t* record) {
    table->records[table->num_records++] = *record;
}

// Function to print a table
void print_table(table_t* table) {
    printf("Table: %s\n", table->name);
    printf("Records:\n");
    for (int i = 0; i < table->num_records; i++) {
        record_t* record = &table->records[i];
        printf("  Record %d:\n", i+1);
        for (int j = 0; j < record->num_fields; j++) {
            field_t* field = &record->fields[j];
            printf("    %s (%d bytes)\n", field->name, field->size);
        }
    }
}

// Main function
int main() {
    // Create a new table
    table_t* table = create_table("My Table");

    // Add some records to the table
    record_t record1;
    strcpy(record1.fields[0].name, "ID");
    record1.fields[0].type = 1;
    record1.fields[0].size = 4;
    strcpy(record1.fields[1].name, "Name");
    record1.fields[1].type = 2;
    record1.fields[1].size = 50;
    add_record(table, &record1);

    record_t record2;
    strcpy(record2.fields[0].name, "Age");
    record2.fields[0].type = 3;
    record2.fields[0].size = 4;
    add_record(table, &record2);

    // Print the table
    print_table(table);

    return 0;
}