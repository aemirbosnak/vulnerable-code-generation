//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a record
typedef struct {
    int id;
    char name[50];
    float salary;
} Record;

// Define the structure of a table
typedef struct {
    Record* records;
    int numRecords;
    int maxRecords;
} Table;

// Create a new table with the given size
Table* createTable(int size) {
    Table* table = (Table*)malloc(sizeof(Table));
    table->records = (Record*)malloc(size * sizeof(Record));
    table->numRecords = 0;
    table->maxRecords = size;
    return table;
}

// Add a new record to the table
void addRecord(Table* table, int id, char* name, float salary) {
    if (table->numRecords == table->maxRecords) {
        printf("Error: Table is full.\n");
        return;
    }
    Record* record = &table->records[table->numRecords];
    record->id = id;
    strcpy(record->name, name);
    record->salary = salary;
    table->numRecords++;
}

// Search for a record in the table by ID
Record* searchRecord(Table* table, int id) {
    for (int i = 0; i < table->numRecords; i++) {
        Record* record = &table->records[i];
        if (record->id == id) {
            return record;
        }
    }
    return NULL;
}

// Print the records in the table
void printRecords(Table* table) {
    for (int i = 0; i < table->numRecords; i++) {
        Record* record = &table->records[i];
        printf("ID: %d, Name: %s, Salary: %.2f\n", record->id, record->name, record->salary);
    }
}

// Main function
int main() {
    // Create a new table with 10 records
    Table* table = createTable(10);

    // Add some records to the table
    addRecord(table, 1, "John Doe", 50000);
    addRecord(table, 2, "Jane Smith", 60000);
    addRecord(table, 3, "Jim Brown", 70000);

    // Print the records in the table
    printRecords(table);

    // Search for a record by ID
    Record* record = searchRecord(table, 2);
    if (record!= NULL) {
        printf("Found record with ID %d:\n", record->id);
        printf("Name: %s, Salary: %.2f\n", record->name, record->salary);
    } else {
        printf("Record not found.\n");
    }

    // Free the memory used by the table
    free(table->records);
    free(table);

    return 0;
}