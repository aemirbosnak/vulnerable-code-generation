//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: realistic
/*
 * A unique C database simulation example program in a realistic style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a record in the database
struct Record {
    int id;
    char name[50];
    int age;
};

// Function to print a record
void printRecord(struct Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
}

// Function to insert a record into the database
void insertRecord(struct Record* records, int* numRecords, struct Record record) {
    records[*numRecords] = record;
    (*numRecords)++;
}

// Function to search for a record in the database
struct Record* searchRecord(struct Record* records, int numRecords, int id) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void updateRecord(struct Record* records, int numRecords, int id, struct Record record) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            records[i] = record;
            break;
        }
    }
}

// Function to delete a record from the database
void deleteRecord(struct Record* records, int* numRecords, int id) {
    for (int i = 0; i < *numRecords; i++) {
        if (records[i].id == id) {
            for (int j = i; j < *numRecords - 1; j++) {
                records[j] = records[j + 1];
            }
            (*numRecords)--;
            break;
        }
    }
}

int main() {
    // Declare a dynamic array to store records
    struct Record* records = (struct Record*)malloc(sizeof(struct Record) * 100);
    int numRecords = 0;

    // Insert some records
    struct Record record1 = {1, "John", 25};
    insertRecord(records, &numRecords, record1);
    struct Record record2 = {2, "Jane", 30};
    insertRecord(records, &numRecords, record2);
    struct Record record3 = {3, "Bob", 40};
    insertRecord(records, &numRecords, record3);

    // Print all records
    printf("All records:\n");
    for (int i = 0; i < numRecords; i++) {
        printRecord(records[i]);
    }

    // Search for a record
    struct Record* record = searchRecord(records, numRecords, 2);
    if (record != NULL) {
        printf("Record found: ");
        printRecord(*record);
    } else {
        printf("Record not found.\n");
    }

    // Update a record
    struct Record record4 = {2, "Jane Doe", 35};
    updateRecord(records, numRecords, 2, record4);
    printf("Updated record: ");
    printRecord(record4);

    // Delete a record
    deleteRecord(records, &numRecords, 1);
    printf("Deleted record: ");
    printRecord(record1);

    // Print all records again
    printf("All records again:\n");
    for (int i = 0; i < numRecords; i++) {
        printRecord(records[i]);
    }

    // Free memory
    free(records);

    return 0;
}