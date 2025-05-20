//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 10

// Define the structure of a record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Declare the array of records
Record records[MAX_RECORDS];

// Define a function to display a record
void displayRecord(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
}

// Define a function to add a new record
void addRecord() {
    // Check if there is space for a new record
    if (sizeof(records)/sizeof(*records) < MAX_RECORDS) {
        // Ask the user for the details of the new record
        Record newRecord;
        printf("Enter ID: ");
        scanf("%d", &newRecord.id);
        printf("Enter Name: ");
        scanf("%s", newRecord.name);
        printf("Enter Age: ");
        scanf("%d", &newRecord.age);
        // Add the new record to the array of records
        records[sizeof(records)/sizeof(*records)] = newRecord;
        printf("Record added successfully!\n");
    } else {
        printf("Cannot add new record, maximum number of records reached.\n");
    }
}

// Define a function to search for a record
void searchRecord() {
    // Ask the user for the ID of the record to search for
    int id;
    printf("Enter ID to search for: ");
    scanf("%d", &id);
    // Search for the record in the array of records
    int index = -1;
    for (int i = 0; i < sizeof(records)/sizeof(*records); i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }
    // Display the record if found, or a message if not found
    if (index == -1) {
        printf("Record not found!\n");
    } else {
        displayRecord(records[index]);
    }
}

// Define a function to update a record
void updateRecord() {
    // Ask the user for the ID of the record to update
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    // Search for the record in the array of records
    int index = -1;
    for (int i = 0; i < sizeof(records)/sizeof(*records); i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }
    // Ask the user for the new details of the record, if found
    if (index == -1) {
        printf("Record not found!\n");
    } else {
        Record newRecord;
        printf("Enter new Name (or hit Enter to keep the existing one): ");
        char newName[50];
        fgets(newName, sizeof(newName), stdin);
        if (strcmp(newName, "\n") == 0) {
            strcpy(newRecord.name, records[index].name);
        } else {
            sscanf(newName, "%s", newRecord.name);
        }
        printf("Enter new Age (or enter -1 to keep the existing one): ");
        int newAge;
        scanf("%d", &newAge);
        if (newAge == -1) {
            newRecord.age = records[index].age;
        } else {
            newRecord.age = newAge;
        }
        // Update the record in the array of records
        records[index] = newRecord;
        printf("Record updated successfully!\n");
    }
}

// Define a function to delete a record
void deleteRecord() {
    // Ask the user for the ID of the record to delete
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    // Search for the record in the array of records
    int index = -1;
    for (int i = 0; i < sizeof(records)/sizeof(*records); i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }
    // Delete the record if found, or display a message if not found
    if (index == -1) {
        printf("Record not found!\n");
    } else {
        for (int i = index; i < sizeof(records)/sizeof(*records) - 1; i++) {
            records[i] = records[i + 1];
        }
        printf("Record deleted successfully!\n");
    }
}

// Define the main function
int main() {
    while (1) {
        // Display the menu of options
        printf("Main Menu:\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        // Ask the user for their choice
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1: addRecord(); break;
            case 2: searchRecord(); break;
            case 3: updateRecord(); break;
            case 4: deleteRecord(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}