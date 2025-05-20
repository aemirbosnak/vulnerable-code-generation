//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define structure for database record
typedef struct Record {
    int id;
    char name[20];
    int age;
} Record;

// Define global array to simulate database
Record database[100];
int numRecords = 0;

// Function to add a record to the database
void addRecord() {
    Record record;

    printf("Enter ID: ");
    scanf("%d", &record.id);

    printf("Enter name: ");
    scanf("%s", record.name);

    printf("Enter age: ");
    scanf("%d", &record.age);

    database[numRecords++] = record;

    printf("Record added successfully.\n");
}

// Function to display all records in the database
void displayRecords() {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("ID\tName\tAge\n");
    printf("--------------------\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Function to search for a record by ID
void searchRecord() {
    int id;
    printf("Enter ID to search for: ");
    scanf("%d", &id);

    for (int i = 0; i < numRecords; i++) {
        if (database[i].id == id) {
            printf("Record found: %d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nDATABASE MENU\n");
        printf("1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Search for record\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting database program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}