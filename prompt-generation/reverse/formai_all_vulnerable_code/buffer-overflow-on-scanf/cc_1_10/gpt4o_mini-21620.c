//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_STRING_LEN 100

typedef struct Record {
    int id;
    char name[MAX_STRING_LEN];
    struct Record *next;
} Record;

typedef struct Index {
    int id;
    Record *record; // Pointer to the Record
} Index;

Record *records[MAX_RECORDS];
Index *indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void freeMemory() {
    for (int i = 0; i < recordCount; i++) {
        free(records[i]);
    }
    for (int j = 0; j < indexCount; j++) {
        free(indexTable[j]);
    }
}

int addRecord(int id, const char *name) {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached!\n");
        return -1;
    }
    Record *newRecord = (Record *)malloc(sizeof(Record));
    if (!newRecord) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    newRecord->id = id;
    strncpy(newRecord->name, name, MAX_STRING_LEN);
    newRecord->next = NULL;

    records[recordCount++] = newRecord;

    Index *newIndex = (Index *)malloc(sizeof(Index));
    if (!newIndex) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(newRecord);
        exit(1);
    }
    newIndex->id = id;
    newIndex->record = newRecord;
    indexTable[indexCount++] = newIndex;

    return 0;
}

Record *searchRecord(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i]->id == id) {
            return indexTable[i]->record;
        }
    }
    return NULL;
}

void displayRecords() {
    printf("Records in Database:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s\n", records[i]->id, records[i]->name);
    }
}

int main() {
    int choice;
    int id;
    char name[MAX_STRING_LEN];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter Name: ");
                if (scanf(" %[^\n]", name) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a valid name.\n");
                    while(getchar() != '\n');
                    continue;
                }
                addRecord(id, name);
                break;
            case 2:
                printf("Enter ID to search: ");
                if (scanf("%d", &id) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                Record *record = searchRecord(id);
                if (record) {
                    printf("Found Record - ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}