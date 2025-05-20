//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define MAX_NUM_RECORDS 100

// Declare a struct to represent a record in the database
typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
} Record;

// Declare an array to represent the database
Record database[MAX_NUM_RECORDS];
int numRecords = 0;

// Function to add a new record to the database
void addRecord(int id, char *name, int age) {
    if (numRecords < MAX_NUM_RECORDS) {
        Record newRecord = {id, "", age};
        strncpy(newRecord.name, name, MAX_STRING_LENGTH);
        database[numRecords++] = newRecord;
        printf("Record added successfully!\n");
    }
    else {
        printf("Error: database is full!\n");
    }
}

// Function to delete a record with the given ID from the database
void deleteRecord(int id) {
    int i;
    bool recordFound = false;
    for (i = 0; i < numRecords; i++) {
        if (database[i].id == id) {
            recordFound = true;
            break;
        }
    }
    if (recordFound) {
        for (int j = i; j < numRecords; j++) {
            database[j] = database[j+1];
        }
        numRecords--;
        printf("Record deleted successfully!\n");
    }
    else {
        printf("Error: record with ID %d not found!\n", id);
    }
}

// Function to display all records in the database
void displayRecords() {
    printf("\nID\tName\t\tAge\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%-15s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Main function to run the program
int main() {
    char choice;
    int id, age;
    char name[MAX_STRING_LENGTH];
    do {
        printf("\nDatabase Menu\n");
        printf("-------------\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Display all records\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                addRecord(id, name, age);
                break;
            case '2':
                printf("Enter ID of record to be deleted: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case '3':
                displayRecords();
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != '4');
    return 0;
}