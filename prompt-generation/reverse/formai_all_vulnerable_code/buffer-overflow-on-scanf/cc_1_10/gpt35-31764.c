//FormAI DATASET v1.0 Category: Database querying ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to display menu
void displayMenu() {
    printf("Welcome to the Artistic Database Querying Program!\n");
    printf("1. Add a new record\n");
    printf("2. Update an existing record\n");
    printf("3. Delete a record\n");
    printf("4. Search for a record\n");
    printf("5. Display all records\n");
    printf("6. Quit the program\n");
}

// Struct for the database record
typedef struct Record {
    int id;
    char name[50];
    char address[100];
    int age;
} Record;

// Array to store the records
Record records[100];
int numRecords = 0;

// Function to add a new record
void addRecord() {
    Record newRecord;
    printf("Enter the name: ");
    fgets(newRecord.name, 50, stdin);
    printf("Enter the address: ");
    fgets(newRecord.address, 100, stdin);
    printf("Enter the age: ");
    scanf("%d", &newRecord.age);
    newRecord.id = numRecords+1;
    records[numRecords] = newRecord;
    numRecords++;
    printf("Record added successfully!\n");
}

// Function to update an existing record
void updateRecord() {
    int id;
    printf("Enter the ID of the record you want to update: ");
    scanf("%d", &id);
    for(int i=0; i<numRecords; i++) {
        if(records[i].id == id) {
            printf("Enter the updated name: ");
            fgets(records[i].name, 50, stdin);
            printf("Enter the updated address: ");
            fgets(records[i].address, 100, stdin);
            printf("Enter the updated age: ");
            scanf("%d", &records[i].age);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("No record found with ID %d\n", id);
}

// Function to delete a record
void deleteRecord() {
    int id;
    printf("Enter the ID of the record you want to delete: ");
    scanf("%d", &id);
    for(int i=0; i<numRecords; i++) {
        if(records[i].id == id) {
            for(int j=i; j<numRecords; j++) {
                records[j] = records[j+1];
            }
            numRecords--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("No record found with ID %d\n", id);
}

// Function to search for a record
void searchRecord() {
    char name[50];
    printf("Enter the name of the record you want to search for: ");
    fgets(name, 50, stdin);
    for(int i=0; i<numRecords; i++) {
        if(strcmp(records[i].name, name) == 0) {
            printf("Record found: ID=%d, Name=%s, Address=%s, Age=%d\n", records[i].id, records[i].name, records[i].address, records[i].age);
            return;
        }
    }
    printf("No record found with name %s\n", name);
}

// Function to display all records
void displayRecords() {
    printf("ID\tName\tAddress\tAge\n");
    for(int i=0; i<numRecords; i++) {
        printf("%d\t%s\t%s\t%d\n", records[i].id, records[i].name, records[i].address, records[i].age);
    }
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                updateRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                displayRecords();
                break;
            case 6:
                printf("Thanks for using the Artistic Database Querying Program!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);
    return 0;
}