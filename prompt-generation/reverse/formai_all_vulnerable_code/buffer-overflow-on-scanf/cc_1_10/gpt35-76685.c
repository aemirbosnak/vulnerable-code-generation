//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_CITY_LENGTH 20
#define MAX_STATE_LENGTH 20
#define ZIPCODE_LENGTH 10
#define PHONE_LENGTH 15

// Struct to store record details
typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char city[MAX_CITY_LENGTH];
    char state[MAX_STATE_LENGTH];
    char zipCode[ZIPCODE_LENGTH];
    char phone[PHONE_LENGTH];
} Record;

// Global variables
Record database[MAX_RECORDS];
int recordCount = 0;

// Add a new record to the database
void addRecord() {
    Record newRecord;
    printf("Enter name: ");
    fgets(newRecord.name, MAX_NAME_LENGTH, stdin);
    printf("Enter address: ");
    fgets(newRecord.address, MAX_ADDRESS_LENGTH, stdin);
    printf("Enter city: ");
    fgets(newRecord.city, MAX_CITY_LENGTH, stdin);
    printf("Enter state: ");
    fgets(newRecord.state, MAX_STATE_LENGTH, stdin);
    printf("Enter zip code: ");
    fgets(newRecord.zipCode, ZIPCODE_LENGTH, stdin);
    printf("Enter phone number: ");
    fgets(newRecord.phone, PHONE_LENGTH, stdin);
    database[recordCount] = newRecord;
    recordCount++;
    printf("Record added successfully!\n");
}

// Delete a record from the database
void deleteRecord() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    int index = -1;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(name, database[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record not found!\n");
    } else {
        for (int i = index; i < recordCount - 1; i++) {
            database[i] = database[i + 1];
        }
        recordCount--;
        printf("Record deleted successfully!\n");
    }
}

// Search for a record in the database
void searchRecord() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    int index = -1;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(name, database[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record not found!\n");
    } else {
        printf("Record found:\n");
        printf("Name: %s", database[index].name);
        printf("Address: %s", database[index].address);
        printf("City: %s", database[index].city);
        printf("State: %s", database[index].state);
        printf("Zip Code: %s", database[index].zipCode);
        printf("Phone Number: %s", database[index].phone);
    }
}

// Display all records in the database
void displayRecords() {
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s", database[i].name);
        printf("Address: %s", database[i].address);
        printf("City: %s", database[i].city);
        printf("State: %s", database[i].state);
        printf("Zip Code: %s", database[i].zipCode);
        printf("Phone Number: %s", database[i].phone);
    }
}

int main() {
    while (1) {
        printf("DATABASE SIMULATION\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Search for a record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}