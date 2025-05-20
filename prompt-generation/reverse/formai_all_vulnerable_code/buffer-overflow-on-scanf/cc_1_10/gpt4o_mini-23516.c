//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

typedef struct {
    int id;
    int index;
} IndexEntry;

Record records[MAX_RECORDS];
IndexEntry indexTable[MAX_RECORDS];
int recordCount = 0;

void addRecord(int id, const char* name) {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    records[recordCount].id = id;
    strncpy(records[recordCount].name, name, MAX_NAME_LEN);
    indexTable[recordCount].id = id;
    indexTable[recordCount].index = recordCount;
    recordCount++;
    printf("Record added: ID = %d, Name = %s\n", id, name);
}

int findRecordById(int id) {
    for (int i = 0; i < recordCount; i++) {
        if (indexTable[i].id == id) {
            return indexTable[i].index;
        }
    }
    return -1;  // Not found
}

void displayRecord(int index) {
    if (index >= 0 && index < recordCount) {
        printf("Record found: ID = %d, Name = %s\n", records[index].id, records[index].name);
    } else {
        printf("Record not found!\n");
    }
}

void displayAllRecords() {
    printf("All Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID = %d, Name = %s\n", records[i].id, records[i].name);
    }
}

int main() {
    int choice, id;
    char name[MAX_NAME_LEN];

    while (1) {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Find Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Add Record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                addRecord(id, name);
                break;
            case 2:  // Find Record by ID
                printf("Enter ID to find: ");
                scanf("%d", &id);
                int recordIndex = findRecordById(id);
                displayRecord(recordIndex);
                break;
            case 3:  // Display All Records
                displayAllRecords();
                break;
            case 4:  // Exit
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}