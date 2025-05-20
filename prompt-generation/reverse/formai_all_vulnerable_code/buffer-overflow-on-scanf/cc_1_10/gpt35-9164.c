//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a record in the database
typedef struct Record {
    int id;
    char name[20];
    int age;
} Record;

// Function declarations
void addRecord(Record *database, int *numOfRecords);
void deleteRecord(Record *database, int *numOfRecords);
void searchRecord(Record *database, int numOfRecords);
void displayDatabase(Record *database, int numOfRecords);

int main() {
    Record *database = NULL;
    int numOfRecords = 0, choice;

    printf("*** Welcome to the Database Simulation ***\n");

    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display Database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(database, &numOfRecords);
                break;
            case 2:
                deleteRecord(database, &numOfRecords);
                break;
            case 3:
                searchRecord(database, numOfRecords);
                break;
            case 4:
                displayDatabase(database, numOfRecords);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add record to the database
void addRecord(Record *database, int *numOfRecords) {
    database = (Record *) realloc(database, (*numOfRecords + 1) * sizeof(Record));
    if (database == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    printf("\nEnter details for Record %d:\n", *numOfRecords + 1);
    printf("ID: ");
    scanf("%d", &(database[*numOfRecords].id));
    printf("Name: ");
    scanf("%s", database[*numOfRecords].name);
    printf("Age: ");
    scanf("%d", &(database[*numOfRecords].age));

    (*numOfRecords)++;
    printf("Record added successfully.\n");
}

// Function to delete record from the database
void deleteRecord(Record *database, int *numOfRecords) {
    int id, i, j;

    printf("\nEnter ID of Record to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *numOfRecords; i++) {
        if (database[i].id == id) {
            for (j = i; j < *numOfRecords - 1; j++) {
                database[j] = database[j + 1];
            }

            database = (Record *) realloc(database, (*numOfRecords - 1) * sizeof(Record));
            if (database == NULL) {
                printf("Error: Memory allocation failed.\n");
                return;
            }

            (*numOfRecords)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("Error: Record with the ID %d not found.\n", id);
}

// Function to search for a record in the database
void searchRecord(Record *database, int numOfRecords) {
    int id, i;

    printf("\nEnter ID of Record to search: ");
    scanf("%d", &id);

    for (i = 0; i < numOfRecords; i++) {
        if (database[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
            return;
        }
    }

    printf("Record with the ID %d not found.\n", id);
}

// Function to display the entire database
void displayDatabase(Record *database, int numOfRecords) {
    if (numOfRecords == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("\nDatabase:\n");

    int i;
    for (i = 0; i < numOfRecords; i++) {
        printf("ID: %d\nName: %s\nAge: %d\n\n", database[i].id, database[i].name, database[i].age);
    }
}