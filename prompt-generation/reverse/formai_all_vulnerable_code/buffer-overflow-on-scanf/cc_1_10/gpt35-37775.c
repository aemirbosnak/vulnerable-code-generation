//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Struct to represent a record in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Global array to store all records
Record database[MAX_RECORDS];

// Global variable to keep track of number of records in the database
int numRecords = 0;

// Function to add a new record to the database
void addRecord(int id, char name[], int age) {
    // Create a new record
    Record newRecord = {
        .id = id,
        .age = age
    };
    strcpy(newRecord.name, name);
    
    // Add the new record to the database
    database[numRecords++] = newRecord;
    printf("Record added to database.\n");
}

// Function to display all records in the database
void displayRecords() {
    if(numRecords == 0) {
        printf("Database is empty.\n");
        return;
    }
    
    printf("ID\tName\tAge\n");
    printf("-----------------------------------\n");
    for(int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Function to search for a record by ID
void searchById(int id) {
    for(int i = 0; i < numRecords; i++) {
        if(database[i].id == id) {
            printf("ID\tName\tAge\n");
            printf("-----------------------------------\n");
            printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
            return;
        }
    }
    
    printf("Record with ID %d was not found.\n", id);
}

// Function to delete a record by ID
void deleteById(int id) {
    for(int i = 0; i < numRecords; i++) {
        if(database[i].id == id) {
            // Shift all records after the deleted record one position to the left
            for(int j = i; j < numRecords - 1; j++) {
                database[j] = database[j+1];
            }
            numRecords--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    
    printf("Record with ID %d was not found.\n", id);
}

int main() {
    int choice, id, age;
    char name[50];
    
    while(1) {
        printf("Menu:\n");
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Search by ID\n");
        printf("4. Delete by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                addRecord(id, name, age);
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                searchById(id);
                break;
            case 4:
                printf("Enter ID: ");
                scanf("%d", &id);
                deleteById(id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}