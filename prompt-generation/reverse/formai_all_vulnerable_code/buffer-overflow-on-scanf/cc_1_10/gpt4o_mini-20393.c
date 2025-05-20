//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_NAME_LENGTH 10

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int recordId;
    char indexValue[INDEX_NAME_LENGTH];
} Index;

Record records[MAX_RECORDS];
Index indexList[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    
    printf("Enter Record ID: ");
    scanf("%d", &records[recordCount].id);
    printf("Enter Record Name: ");
    scanf("%s", records[recordCount].name);

    // Create index for the current record
    strcpy(indexList[indexCount].indexValue, records[recordCount].name);
    indexList[indexCount].recordId = recordCount;

    recordCount++;
    indexCount++;
    printf("Record added successfully!\n");
}

void searchRecord() {
    char searchName[NAME_LENGTH];
    printf("Enter Name to Search: ");
    scanf("%s", searchName);

    int found = 0;
    
    for (int i = 0; i < indexCount; i++) {
        if (strcmp(indexList[i].indexValue, searchName) == 0) {
            found = 1;
            Record record = records[indexList[i].recordId];
            printf("Record Found: ID: %d, Name: %s\n", record.id, record.name);
        }
    }

    if (!found) {
        printf("No records found with the name '%s'.\n", searchName);
    }
}

void displayRecords() {
    if (recordCount == 0) {
        printf("No records available.\n");
        return;
    }
    
    printf("\n--- All Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s\n", records[i].id, records[i].name);
    }
    printf("--------------------\n");
}

void displayIndex() {
    if (indexCount == 0) {
        printf("No index available.\n");
        return;
    }

    printf("\n--- Index Records ---\n");
    for (int i = 0; i < indexCount; i++) {
        printf("Index Value: %s, Record ID: %d\n", indexList[i].indexValue, indexList[i].recordId);
    }
    printf("---------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Search Record by Name\n");
        printf("3. Display All Records\n");
        printf("4. Display Index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                displayIndex();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0; // Never reached
}