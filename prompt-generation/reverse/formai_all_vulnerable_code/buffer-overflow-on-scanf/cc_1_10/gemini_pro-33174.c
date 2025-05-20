//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a record in our database
typedef struct {
    int id;
    char name[50];
    char email[50];
    int age;
} Record;

// Define the maximum number of records in our database
#define MAX_RECORDS 100

// Define the database itself
Record database[MAX_RECORDS];

// Define the current number of records in our database
int num_records = 0;

//Function to scan record details
void scanRecord(Record *record){
    printf("Enter ID: ");
    scanf(" %d",&record->id);
    printf("Enter name: ");
    scanf(" %s",record->name);
    printf("Enter email: ");
    scanf(" %s",record->email);
    printf("Enter age: ");
    scanf(" %d",&record->age);
}

// Function to add a new record to our database
void addRecord() {
    // Check if the database is full
    if (num_records == MAX_RECORDS) {
        printf("Database is full! Cannot add new record.\n");
        return;
    }

    // Get the details of the new record from the user
    Record newRecord;
    scanRecord(&newRecord);

    // Add the new record to the database
    database[num_records++] = newRecord;

    // Print a success message to the user
    printf("New record added successfully!\n");
}

// Function to delete a record from our database
void deleteRecord() {
    // Get the ID of the record to be deleted from the user
    int id;
    printf("Enter the ID of the record to be deleted: ");
    scanf("%d", &id);

    // Find the record in the database
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the record was found
    if (index == -1) {
        printf("Record not found!\n");
        return;
    }

    // Delete the record from the database
    for (int i = index; i < num_records - 1; i++) {
        database[i] = database[i + 1];
    }
    num_records--;

    // Print a success message to the user
    printf("Record deleted successfully!\n");
}

// Function to update a record in our database
void updateRecord() {
    // Get the ID of the record to be updated from the user
    int id;
    printf("Enter the ID of the record to be updated: ");
    scanf("%d", &id);

    // Find the record in the database
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the record was found
    if (index == -1) {
        printf("Record not found!\n");
        return;
    }

    // Get the updated details of the record from the user
    Record updatedRecord;
    scanRecord(&updatedRecord);

    // Update the record in the database
    database[index] = updatedRecord;

    // Print a success message to the user
    printf("Record updated successfully!\n");
}

// Function to print all records in the database 
void displayRecords() {
    // Check if the database is empty
    if (num_records == 0) {
        printf("Database is empty! No records to display.\n");
        return;
    }

    // Print the header of the table
    printf("ID\tName\tEmail\t\tAge\n");

    // Print the records in the table
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%s\t\t%d\n", database[i].id, database[i].name, database[i].email, database[i].age);
    }
}
int main() {
    // Print a welcome message to the user
    printf("Welcome to my awesome database management system!\n");

    // Display the menu of options to the user
    int choice;
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new record\n");
        printf("2. Delete a record\n");
        printf("3. Update a record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Thank you for using my database management system!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}