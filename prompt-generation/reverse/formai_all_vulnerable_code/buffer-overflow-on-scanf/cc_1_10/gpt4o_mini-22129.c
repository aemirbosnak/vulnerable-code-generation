//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 100

typedef struct {
    int id;
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
} Record;

typedef struct {
    int id;
    int recordIndex; // Index of the record in 'records' array
} IndexEntry;

Record records[MAX_RECORDS];
IndexEntry indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void addRecord(int id, const char* name, const char* email) {
    if (recordCount < MAX_RECORDS) {
        records[recordCount].id = id;
        strncpy(records[recordCount].name, name, MAX_LENGTH);
        strncpy(records[recordCount].email, email, MAX_LENGTH);

        // Add to index
        indexTable[indexCount].id = id;
        indexTable[indexCount].recordIndex = recordCount;
        indexCount++;

        recordCount++;
        printf("Record added: %d, %s, %s\n", id, name, email);
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

int searchRecord(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id) {
            return indexTable[i].recordIndex;
        }
    }
    return -1; // Not found
}

void displayRecord(Record record) {
    printf("ID: %d\nName: %s\nEmail: %s\n", record.id, record.name, record.email);
}

void viewAllRecords() {
    if (recordCount == 0) {
        printf("No records to display.\n");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        displayRecord(records[i]);
        printf("\n");
    }
}

void deleteRecord(int id) {
    int recordIndex = searchRecord(id);
    if (recordIndex == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }

    // Shift records to delete the item
    for (int i = recordIndex; i < recordCount - 1; i++) {
        records[i] = records[i + 1];
    }
    recordCount--;

    // Rebuild the index
    indexCount = 0;
    for (int i = 0; i < recordCount; i++) {
        indexTable[indexCount].id = records[i].id;
        indexTable[indexCount].recordIndex = i;
        indexCount++;
    }

    printf("Record with ID %d deleted.\n", id);
}

int main() {
    int choice, id;
    char name[MAX_LENGTH], email[MAX_LENGTH];

    while (1) {
        printf("Database Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. View All Records\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                addRecord(id, name, email);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int recordIndex = searchRecord(id);
                if (recordIndex != -1) {
                    displayRecord(records[recordIndex]);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                viewAllRecords();
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}