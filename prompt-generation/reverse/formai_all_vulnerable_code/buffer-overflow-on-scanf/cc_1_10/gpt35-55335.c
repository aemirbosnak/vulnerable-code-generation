//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the database record
struct Record {
    int id;
    char name[20];
    int age;
    double salary;
};

// Declare global variables
int numRecords = 0;
struct Record *records = NULL;

// Function to add a new record to the database
void addRecord(int id, char *name, int age, double salary) {
    // Increase the size of the records array
    numRecords++;
    records = (struct Record *) realloc(records, numRecords * sizeof(struct Record));

    // Add the new record to the end of the array
    records[numRecords-1].id = id;
    strcpy(records[numRecords-1].name, name);
    records[numRecords-1].age = age;
    records[numRecords-1].salary = salary;

    printf("Record added successfully.\n");
}

// Function to remove a record from the database by ID
void removeRecord(int id) {
    int i, j;

    // Find the record with the given ID
    for (i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            // Shift all the records after this one back by one
            for (j = i; j < numRecords-1; j++) {
                records[j] = records[j+1];
            }

            // Decrease the size of the records array
            numRecords--;
            records = (struct Record *) realloc(records, numRecords * sizeof(struct Record));

            printf("Record removed successfully.\n");
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

// Function to print all the records in the database
void printRecords() {
    int i;

    printf("ID \tName \tAge \tSalary\n");
    printf("======================================\n");

    for (i = 0; i < numRecords; i++) {
        printf("%d \t%s \t%d \t%.2lf\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
}

int main() {
    int choice;
    int id, age;
    char name[20];
    double salary;

    // Display the menu and prompt for user input
    do {
        printf("\nDatabase Menu\n");
        printf("1. Add a new record\n");
        printf("2. Remove a record by ID\n");
        printf("3. Print all records\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a new record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter salary: ");
                scanf("%lf", &salary);

                addRecord(id, name, age, salary);
                break;

            case 2: // Remove a record by ID
                printf("Enter ID: ");
                scanf("%d", &id);

                removeRecord(id);
                break;

            case 3: // Print all records
                printRecords();
                break;

            case 4: // Quit
                break;

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Free the memory used by the records array
    free(records);

    return 0;
}