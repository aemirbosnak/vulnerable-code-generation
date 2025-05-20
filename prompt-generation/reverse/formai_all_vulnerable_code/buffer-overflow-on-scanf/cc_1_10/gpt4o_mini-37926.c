//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Structure to represent a record
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// Structure to represent an index
typedef struct {
    int id;
    int recordIndex;
} Index;

// Global variables for records and index
Record records[MAX_RECORDS];
Index indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

// Function to add a new record
void addRecord(int id, const char *name, const char *phone) {
    if (recordCount >= MAX_RECORDS) {
        printf("Error: Record limit reached.\n");
        return;
    }
    records[recordCount].id = id;
    strncpy(records[recordCount].name, name, MAX_NAME_LENGTH);
    strncpy(records[recordCount].phone, phone, MAX_PHONE_LENGTH);
    
    // Update the index table
    indexTable[indexCount].id = id;
    indexTable[indexCount].recordIndex = recordCount;
    indexCount++;
    
    recordCount++;
}

// Function to search a record by ID
Record* searchRecordById(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id) {
            return &records[indexTable[i].recordIndex];
        }
    }
    return NULL;
}

// Function to display a record
void displayRecord(const Record *rec) {
    if (rec != NULL) {
        printf("ID: %d, Name: %s, Phone: %s\n", rec->id, rec->name, rec->phone);
    } else {
        printf("Record not found.\n");
    }
}

// Function to display all records
void displayAllRecords() {
    printf("All Records:\n");
    for (int i = 0; i < recordCount; i++) {
        displayRecord(&records[i]);
    }
}

// Function to sort index by ID
void sortIndex() {
    for (int i = 0; i < indexCount - 1; i++) {
        for (int j = 0; j < indexCount - i - 1; j++) {
            if (indexTable[j].id > indexTable[j + 1].id) {
                Index temp = indexTable[j];
                indexTable[j] = indexTable[j + 1];
                indexTable[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Search Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                addRecord(id, name, phone);
                sortIndex();
                break;

            case 2: // Search record
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record* record = searchRecordById(id);
                displayRecord(record);
                break;

            case 3: // Display all records
                displayAllRecords();
                break;

            case 4: // Exit
                printf("Exiting the system...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}