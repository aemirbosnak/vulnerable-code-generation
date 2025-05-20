//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// Structure to store details of each record
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
} Record;

// Structure to implement the Index
typedef struct {
    char name[50];
    int id;
} Index;

// Function to add a new record to the database
void addRecord(Record *database, Index *index, int *numRecords) {
    if (*numRecords >= MAX_RECORDS) {
        printf("The database is full, cannot add any more records.\n");
        return;
    }

    Record newRecord;
    printf("Enter the following details of the new record:\n");
    printf("ID: ");
    scanf("%d", &newRecord.id);
    printf("Name: ");
    scanf("%s", newRecord.name);
    printf("Age: ");
    scanf("%d", &newRecord.age);
    printf("Gender: ");
    scanf("%s", newRecord.gender);

    database[*numRecords] = newRecord;

    // Update the index
    Index newIndex;
    strcpy(newIndex.name, newRecord.name);
    newIndex.id = *numRecords;

    index[*numRecords] = newIndex;

    *numRecords = *numRecords + 1;

    printf("Record added successfully!\n");
}

// Function to search for a record by name
void searchRecord(Record *database, Index *index, int *numRecords) {
    char searchName[50];
    printf("Enter the name to search for: ");
    scanf("%s", searchName);

    for (int i = 0; i < *numRecords; i++) {
        Index currentIndex = index[i];
        if (strcmp(currentIndex.name, searchName) == 0) {
            Record foundRecord = database[currentIndex.id];
            printf("Record found:\n");
            printf("ID: %d\n", foundRecord.id);
            printf("Name: %s\n", foundRecord.name);
            printf("Age: %d\n", foundRecord.age);
            printf("Gender: %s\n", foundRecord.gender);
            return;
        }
    }

    printf("No record found with the given name.\n");
}

int main() {
    Record database[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int numRecords = 0;

    printf("=======================\n");
    printf("Welcome to the Database!\n");
    printf("=======================\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record by name\n");
        printf("3. Exit the program\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(database, index, &numRecords);
                break;
            case 2:
                searchRecord(database, index, &numRecords);
                break;
            case 3:
                printf("Thank you for using the Database! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}