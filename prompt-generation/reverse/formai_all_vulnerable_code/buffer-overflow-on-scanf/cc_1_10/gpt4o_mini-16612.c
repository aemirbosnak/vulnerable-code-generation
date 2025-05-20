//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

// Function to add a new record
void addRecord(Record records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    printf("Enter record ID: ");
    scanf("%d", &records[*count].id);
    printf("Enter record Name: ");
    scanf("%s", records[*count].name);
    (*count)++;
    printf("Record added successfully!\n");
}

// Function to search a record by ID using linear search
void searchRecord(Record records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            printf("Record found: ID = %d, Name = %s\n", records[i].id, records[i].name);
            return;
        }
    }
    printf("No record found with ID = %d\n", id);
}

// Function to display all records
void displayRecords(Record records[], int count) {
    printf("Displaying all records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", records[i].id, records[i].name);
    }
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice, id;

    while (1) {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Search Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(records, count, id);
                break;
            case 3:
                displayRecords(records, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}