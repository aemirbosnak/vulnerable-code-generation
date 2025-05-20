//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id;
    int index; // Points to the record in the records array
} Index;

// Function to add a record to the database
void addRecord(Record records[], Index index[], int *recordCount) {
    if (*recordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    getchar(); // To consume the leftover newline
    printf("Enter Name: ");
    fgets(newRecord.name, NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove the newline character

    records[*recordCount] = newRecord;
    index[*recordCount].id = newRecord.id;
    index[*recordCount].index = *recordCount;
    (*recordCount)++;

    printf("Record added successfully!\n");
}

// Function to display all records
void displayRecords(Record records[], int recordCount) {
    printf("\nAll Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s\n", records[i].id, records[i].name);
    }
}

// Function to search for a record by ID
void searchRecord(Record records[], Index index[], int recordCount) {
    int searchId;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);
    
    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (index[i].id == searchId) {
            found = 1;
            int recordIndex = index[i].index;
            printf("Record Found: ID: %d, Name: %s\n", records[recordIndex].id, records[recordIndex].name);
            break;
        }
    }
    
    if (!found) {
        printf("Record not found.\n");
    }
}

// Function to sort the index based on IDs (simple bubble sort)
void sortIndex(Index index[], int recordCount) {
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - i - 1; j++) {
            if (index[j].id > index[j + 1].id) {
                Index temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }
}

int main() {
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int recordCount = 0;
    int choice;

    do {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(records, index, &recordCount);
                sortIndex(index, recordCount); // Keep the index sorted after addition
                break;
            case 2:
                displayRecords(records, recordCount);
                break;
            case 3:
                searchRecord(records, index, recordCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}