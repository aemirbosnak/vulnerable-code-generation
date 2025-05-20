//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to represent a database record
typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

// Structure to hold the index
typedef struct {
    int id;
    int position;  // Position in the database array
} Index;

// Function to compare records for qsort
int compareRecords(const void *a, const void *b) {
    return ((Record *)a)->id - ((Record *)b)->id;
}

// Function to create and build the index
void createIndex(Record records[], Index indexes[], int recordCount) {
    for (int i = 0; i < recordCount; i++) {
        indexes[i].id = records[i].id;
        indexes[i].position = i;
    }
    qsort(indexes, recordCount, sizeof(Index), compareRecords);
}

// Function to search for a record using the index
Record* searchRecord(Index indexes[], Record records[], int recordCount, int searchId) {
    for (int i = 0; i < recordCount; i++) {
        if (indexes[i].id == searchId) {
            return &records[indexes[i].position]; // Return pointer to the record
        }
    }
    return NULL; // Not found
}

int main() {
    int recordCount = 5;
    Record records[MAX_RECORDS] = {
        {1, "Alice", "alice@example.com"},
        {2, "Bob", "bob@example.com"},
        {3, "Charlie", "charlie@example.com"},
        {4, "David", "david@example.com"},
        {5, "Eve", "eve@example.com"}
    };

    Index indexes[MAX_RECORDS];

    // Create the index
    createIndex(records, indexes, recordCount);

    int searchId;
    printf("Enter the ID of the record you would like to search: ");
    scanf("%d", &searchId);

    Record *result = searchRecord(indexes, records, recordCount, searchId);
    
    if (result != NULL) {
        printf("Record Found: ID: %d, Name: %s, Email: %s\n", result->id, result->name, result->email);
    } else {
        printf("Record with ID %d not found!\n", searchId);
    }

    // Simple Menu to manage records
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. View All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (recordCount < MAX_RECORDS) {
                printf("Enter ID: ");
                scanf("%d", &records[recordCount].id);
                printf("Enter Name: ");
                scanf("%s", records[recordCount].name);
                printf("Enter Email: ");
                scanf("%s", records[recordCount].email);
                recordCount++;
                // Update the index
                createIndex(records, indexes, recordCount);
                printf("Record added successfully!\n");
            } else {
                printf("Database is full, cannot add more records!\n");
            }
        } else if (choice == 2) {
            printf("\nAll Records:\n");
            for (int i = 0; i < recordCount; i++) {
                printf("ID: %d, Name: %s, Email: %s\n", records[i].id, records[i].name, records[i].email);
            }
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}