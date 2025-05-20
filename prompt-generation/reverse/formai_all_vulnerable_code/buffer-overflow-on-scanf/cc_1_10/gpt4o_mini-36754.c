//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_SIZE 50

typedef struct Record {
    int id;
    char name[NAME_SIZE];
    struct Record *next;
} Record;

typedef struct Index {
    Record *head;
} Index;

// Function to create a new record
Record *createRecord(int id, const char *name) {
    Record *newRecord = (Record *)malloc(sizeof(Record));
    if (newRecord == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newRecord->id = id;
    strncpy(newRecord->name, name, NAME_SIZE);
    newRecord->next = NULL;
    return newRecord;
}

// Function to initialize the index
void initIndex(Index *index) {
    index->head = NULL;
}

// Function to insert a record into the index
void insertRecord(Index *index, int id, const char *name) {
    Record *newRecord = createRecord(id, name);
    if (index->head == NULL) {
        index->head = newRecord;
    } else {
        Record *current = index->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRecord;
    }
    printf("Record inserted: ID=%d, NAME=%s\n", id, name);
}

// Function to search for a record by ID
Record *searchRecord(Index *index, int id) {
    Record *current = index->head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display all records in the index
void displayRecords(Index *index) {
    Record *current = index->head;
    if (current == NULL) {
        printf("No records to display.\n");
        return;
    }
    printf("Records in Index:\n");
    while (current != NULL) {
        printf("ID=%d, NAME=%s\n", current->id, current->name);
        current = current->next;
    }
}

// Main function
int main() {
    Index recordIndex;
    initIndex(&recordIndex);

    int choice, id;
    char name[NAME_SIZE];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name); // Note: Be cautious with buffer overflow
                insertRecord(&recordIndex, id, name);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *foundRecord = searchRecord(&recordIndex, id);
                if (foundRecord) {
                    printf("Found Record - ID=%d, NAME=%s\n", foundRecord->id, foundRecord->name);
                } else {
                    printf("Record with ID=%d not found.\n", id);
                }
                break;
            case 3:
                displayRecords(&recordIndex);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}