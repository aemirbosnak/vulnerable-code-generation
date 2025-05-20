//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing data in the database
typedef struct {
    int rollNumber;
    char name[50];
    int age;
    char address[100];
} Student;

// Structure for storing database records
typedef struct {
    int numRecords;
    Student *records;
} Database;

// Function to display a student record
void displayRecord(Student record) {
    printf("Roll Number: %d\n", record.rollNumber);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Address: %s\n", record.address);
}

// Function to add a record to the database
void addRecord(Database *database) {
    // Read data for new record
    Student newRecord;
    printf("Enter Roll Number: ");
    scanf("%d", &newRecord.rollNumber);
    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    printf("Enter Age: ");
    scanf("%d", &newRecord.age);
    printf("Enter Address: ");
    scanf("%s", newRecord.address);

    // Add new record to database
    database->numRecords++;
    database->records = realloc(database->records, database->numRecords * sizeof(Student));
    database->records[database->numRecords - 1] = newRecord;

    printf("Record added successfully!\n");
}

// Function to search for a record in the database
void searchRecord(Database database) {
    // Read roll number to search for
    int rollNumber;
    printf("Enter Roll Number to search for: ");
    scanf("%d", &rollNumber);

    // Search for record with matching roll number
    for (int i = 0; i < database.numRecords; i++) {
        if (database.records[i].rollNumber == rollNumber) {
            printf("Record found:\n");
            displayRecord(database.records[i]);
            return;
        }
    }

    printf("Record not found!\n");
}

// Function to display all records in the database
void displayAllRecords(Database database) {
    printf("All Records in Database:\n");
    for (int i = 0; i < database.numRecords; i++) {
        printf("---------------------------\n");
        displayRecord(database.records[i]);
    }
}

// Main function to run the program
int main() {
    // Initialize empty database
    Database database;
    database.numRecords = 0;
    database.records = NULL;

    int choice = 0;
    while (1) {
        // Display menu of options
        printf("\n\n---DATABASE MENU---\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&database);
                break;
            case 2:
                searchRecord(database);
                break;
            case 3:
                displayAllRecords(database);
                break;
            case 4:
                // Free memory used by database records
                for (int i = 0; i < database.numRecords; i++) {
                    free(database.records[i].name);
                    free(database.records[i].address);
                }
                free(database.records);

                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}