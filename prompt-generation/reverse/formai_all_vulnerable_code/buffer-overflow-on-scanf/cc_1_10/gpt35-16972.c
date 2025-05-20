//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing database records
struct DatabaseRecord {
    char name[50];
    int age;
    float gpa;
};

// Function to print a single record
void printRecord(struct DatabaseRecord record) {
    printf("%s\t%d\t%.2f\n", record.name, record.age, record.gpa);
}

// Function to add a record to the database
void addRecord(struct DatabaseRecord records[], int *numRecords) {
    // Prompt user for input
    printf("Enter name: ");
    scanf("%s", records[*numRecords].name);
    printf("Enter age: ");
    scanf("%d", &records[*numRecords].age);
    printf("Enter GPA: ");
    scanf("%f", &records[*numRecords].gpa);
    printf("Record added!\n");

    // Increment number of records
    (*numRecords)++;
}

// Function to display all records in the database
void displayRecords(struct DatabaseRecord records[], int numRecords) {
    printf("Name\tAge\tGPA\n");
    for (int i = 0; i < numRecords; i++) {
        printRecord(records[i]);
    }
}

// Main function
int main() {
    // Default database capacity
    const int DEFAULT_CAPACITY = 10;

    // Prompt user for desired database capacity
    int capacity;
    printf("Enter database capacity (default %d): ", DEFAULT_CAPACITY);
    scanf("%d", &capacity);

    // Create array of records of specified capacity
    struct DatabaseRecord *records = malloc(capacity * sizeof(struct DatabaseRecord));

    // Keep track of number of records in the database
    int numRecords = 0;

    // Main menu loop
    int choice;
    do {
        printf("\n1. Add record\n2. Display records\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                displayRecords(records, numRecords);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 3);

    // Free memory allocated for array of records
    free(records);

    return 0;
}