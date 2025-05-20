//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    char id[MAX_ID_LENGTH];
    int recordIndex;
} IndexEntry;

Record records[MAX_RECORDS];
IndexEntry indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    Record newRecord;
    printf("Enter ID: ");
    scanf("%s", newRecord.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newRecord.name);
    
    records[recordCount++] = newRecord;
    printf("Record added successfully!\n");
}

void createIndex() {
    indexCount = 0;
    
    for (int i = 0; i < recordCount; i++) {
        strcpy(indexTable[indexCount].id, records[i].id);
        indexTable[indexCount].recordIndex = i;
        indexCount++;
    }
    
    printf("Index created successfully with %d entries!\n", indexCount);
}

int searchIndex(const char* id) {
    for (int i = 0; i < indexCount; i++) {
        if (strcmp(indexTable[i].id, id) == 0) {
            return indexTable[i].recordIndex;
        }
    }
    return -1; // Not found
}

void displayRecord(int index) {
    if (index >= 0 && index < recordCount) {
        printf("ID: %s, Name: %s\n", records[index].id, records[index].name);
    } else {
        printf("Record not found!\n");
    }
}

void searchRecord() {
    char id[MAX_ID_LENGTH];
    printf("Enter ID to search: ");
    scanf("%s", id);
    
    int index = searchIndex(id);
    if (index != -1) {
        displayRecord(index);
    } else {
        printf("Record with ID %s not found!\n", id);
    }
}

void displayAllRecords() {
    if (recordCount == 0) {
        printf("No records found!\n");
        return;
    }
    
    printf("All Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %s, Name: %s\n", records[i].id, records[i].name);
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Database Indexing System Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Create Index\n");
        printf("3. Search Record\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                createIndex();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                displayAllRecords();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}