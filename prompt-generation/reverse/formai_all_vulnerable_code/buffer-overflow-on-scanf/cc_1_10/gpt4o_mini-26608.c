//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record* next;
} Record;

typedef struct IndexNode {
    char name[MAX_NAME_LENGTH];
    Record* record;  // Pointer to the first record with the indexed name
    struct IndexNode* next;
} IndexNode;

// Function to create a new record
Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, MAX_NAME_LENGTH);
    newRecord->next = NULL;
    return newRecord;
}

// Function to insert a new record into the index
void insertRecord(IndexNode** index, int id, const char* name) {
    // Create a new record
    Record* newRecord = createRecord(id, name);

    // Search for the index node
    IndexNode* current = *index;
    IndexNode* prev = NULL;

    while (current != NULL) {
        int cmp = strcmp(name, current->name);
        if (cmp == 0) {
            // If name already exists, add record to the linked list of records
            newRecord->next = current->record;
            current->record = newRecord;
            return;
        } else if (cmp < 0) {
            break;
        }
        prev = current;
        current = current->next;
    }

    // Create a new index node if not found
    IndexNode* newIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
    strncpy(newIndexNode->name, name, MAX_NAME_LENGTH);
    newIndexNode->record = newRecord;
    newIndexNode->next = current;

    if (prev == NULL) {
        *index = newIndexNode;  // Insert at head
    } else {
        prev->next = newIndexNode;  // Insert between prev and current
    }
}

// Function to search for records by name
void searchRecords(IndexNode* index, const char* name) {
    IndexNode* current = index;
    while (current != NULL) {
        if (strcmp(name, current->name) == 0) {
            printf("Records for %s:\n", name);
            Record* record = current->record;
            while (record != NULL) {
                printf("ID: %d, Name: %s\n", record->id, record->name);
                record = record->next;
            }
            return;
        }
        current = current->next;
    }
    printf("No records found for %s.\n", name);
}

// Function to display all records
void displayAllRecords(IndexNode* index) {
    IndexNode* current = index;
    while (current != NULL) {
        printf("Index Name: %s\n", current->name);
        Record* record = current->record;
        while (record != NULL) {
            printf("  ID: %d, Name: %s\n", record->id, record->name);
            record = record->next;
        }
        current = current->next;
    }
}

// Function to free the allocated memory
void freeIndex(IndexNode* index) {
    while (index != NULL) {
        IndexNode* tempIndex = index;
        Record* record = index->record;

        while (record != NULL) {
            Record* tempRecord = record;
            record = record->next;
            free(tempRecord);
        }
        
        index = index->next;
        free(tempIndex);
    }
}

// Main function
int main() {
    IndexNode* index = NULL;
    int choice, id;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Insert Record\n");
        printf("2. Search Records by Name\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertRecord(&index, id, name);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                searchRecords(index, name);
                break;
            case 3:
                displayAllRecords(index);
                break;
            case 4:
                freeIndex(index);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}