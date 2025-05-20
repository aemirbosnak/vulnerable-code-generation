//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id; // This will be used as the index
    int record_index; // Index for accessing the record directly
} IndexEntry;

Record database[MAX_RECORDS]; // Array to hold database records
IndexEntry indexTable[MAX_RECORDS]; // Array to hold index entries

int currentRecordCount = 0; // To keep track of current number of records

void addRecord(int id, const char *name) {
    if (currentRecordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    database[currentRecordCount].id = id;
    strncpy(database[currentRecordCount].name, name, NAME_LENGTH);
    
    // Create index entry
    indexTable[currentRecordCount].id = id;
    indexTable[currentRecordCount].record_index = currentRecordCount;

    currentRecordCount++;
    printf("Record added: ID=%d, Name=%s\n", id, name);
}

int searchRecord(int id) {
    for (int i = 0; i < currentRecordCount; i++) {
        if (indexTable[i].id == id) {
            return indexTable[i].record_index; // Return index of the record
        }
    }
    return -1; // Not found
}

void displayRecord(int index) {
    if (index >= 0 && index < currentRecordCount) {
        printf("Record found: ID=%d, Name=%s\n", database[index].id, database[index].name);
    } else {
        printf("Record not found.\n");
    }
}

void displayAllRecords() {
    printf("All Records:\n");
    for (int i = 0; i < currentRecordCount; i++) {
        printf("ID=%d, Name=%s\n", database[i].id, database[i].name);
    }
}

void deleteRecord(int id) {
    int index = searchRecord(id);
    if (index == -1) {
        printf("Record with ID=%d not found.\n", id);
        return;
    }

    // Shift records to the left to delete the entry
    for (int i = index; i < currentRecordCount - 1; i++) {
        database[i] = database[i + 1];
        indexTable[i] = indexTable[i + 1];
    }

    currentRecordCount--;
    printf("Record with ID=%d deleted.\n", id);
}

void menu() {
    printf("Database Indexing System Menu:\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Display All Records\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add record
                printf("Enter ID and Name: ");
                scanf("%d%s", &id, name);
                addRecord(id, name);
                break;
            case 2: // Search record
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int foundIndex;
                foundIndex = searchRecord(id);
                displayRecord(foundIndex);
                break;
            case 3: // Display all records
                displayAllRecords();
                break;
            case 4: // Delete record
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 5: // Exit
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}