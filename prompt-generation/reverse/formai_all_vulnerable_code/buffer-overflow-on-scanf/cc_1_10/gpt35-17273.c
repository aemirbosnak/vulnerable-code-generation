//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Struct for holding student information
typedef struct {
    char name[20];
    int age;
    int id;
} StudentRecord;

// Global variables
StudentRecord database[MAX_RECORDS];
int numRecords = 0;

// Function to add a record to the database
void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Error: database full.\n");
        return;
    }

    StudentRecord newRecord;

    printf("Enter student name: ");
    scanf("%s", newRecord.name);
    printf("Enter student age: ");
    scanf("%d", &newRecord.age);
    printf("Enter student ID: ");
    scanf("%d", &newRecord.id);

    database[numRecords] = newRecord;
    numRecords++;

    printf("Record added successfully.\n");
}

// Function to search for a record by name
void searchRecord() {
    char name[20];

    printf("Enter student name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("ID: %d\n", database[i].id);
            return;
        }
    }

    printf("Record not found.\n");
}

// Function to print all records in the database
void printRecords() {
    printf("Current records in database:\n");

    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("ID: %d\n", database[i].id);
        printf("\n");
    }
}

int main() {
    int choice;

    // Main program loop
    while (1) {
        printf("\nDatabase options:\n");
        printf("[1] Add record\n");
        printf("[2] Search for record\n");
        printf("[3] Print all records\n");
        printf("[4] Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                printRecords();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}