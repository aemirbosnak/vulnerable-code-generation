//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of records and characters in each record
#define MAX_RECORDS 50
#define MAX_CHARS 100

// Define the structure of each record
struct Record {
    int id;
    char name[MAX_CHARS];
    char address[MAX_CHARS];
    char phone_number[MAX_CHARS];
};

// Define an array of records
struct Record records[MAX_RECORDS];

// Define the number of records in the database
int num_records = 0;

// Function to add a record to the database
void addRecord(int id, char* name, char* address, char* phone) {
    if (num_records == MAX_RECORDS) {
        printf("Error: database is full.\n");
        return;
    }
    
    // Allocate memory for the new record
    struct Record* newRecord = (struct Record*)malloc(sizeof(struct Record));
    
    // Set the values of the new record
    newRecord->id = id;
    strcpy(newRecord->name, name);
    strcpy(newRecord->address, address);
    strcpy(newRecord->phone_number, phone);
    
    // Add the new record to the database
    records[num_records] = *newRecord;
    num_records++;
    
    // Free the memory used by the new record
    free(newRecord);
    
    printf("Record added successfully!\n");
}

// Function to search for a record in the database by ID
void searchRecord(int id) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("Record found!\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Phone Number: %s\n", records[i].phone_number);
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to delete a record from the database by ID
void deleteRecord(int id) {
    int i, found = 0;
    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < num_records - 1; i++) {
            records[i] = records[i + 1];
        }
        num_records--;
        printf("Record deleted successfully!\n");
    }
    else {
        printf("Record not found.\n");
    }
}

// Function to update a record in the database by ID
void updateRecord(int id, char* field, char* value) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            if (strcmp(field, "name") == 0) {
                strcpy(records[i].name, value);
                printf("Record updated successfully!\n");
                return;
            }
            else if (strcmp(field, "address") == 0) {
                strcpy(records[i].address, value);
                printf("Record updated successfully!\n");
                return;
            }
            else if (strcmp(field, "phone") == 0) {
                strcpy(records[i].phone_number, value);
                printf("Record updated successfully!\n");
                return;
            }
            else {
                printf("Error: field not found.\n");
                return;
            }
        }
    }
    printf("Record not found.\n");
}

// Function to display all records in the database
void displayRecords() {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("Record #%d\n", i + 1);
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Address: %s\n", records[i].address);
        printf("Phone Number: %s\n", records[i].phone_number);
    }
}

int main() {
    int choice, id;
    char name[MAX_CHARS], address[MAX_CHARS], phone[MAX_CHARS], field[MAX_CHARS], value[MAX_CHARS];
    
    // Main menu
    do {
        printf("\nDATABASE SIMULATION MENU\n");
        printf("1) Add a record\n");
        printf("2) Search for a record\n");
        printf("3) Delete a record\n");
        printf("4) Update a record\n");
        printf("5) Display all records\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform the selected operation
        switch (choice) {
            case 1:
                printf("Enter the ID: ");
                scanf("%d", &id);
                printf("Enter the name: ");
                scanf("%s", &name);
                printf("Enter the address: ");
                scanf("%s", &address);
                printf("Enter the phone number: ");
                scanf("%s", &phone);
                addRecord(id, name, address, phone);
                break;
            case 2:
                printf("Enter the ID to search for: ");
                scanf("%d", &id);
                searchRecord(id);
                break;
            case 3:
                printf("Enter the ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 4:
                printf("Enter the ID to update: ");
                scanf("%d", &id);
                printf("Enter the field to update (name/address/phone): ");
                scanf("%s", &field);
                printf("Enter the new value: ");
                scanf("%s", &value);
                updateRecord(id, field, value);
                break;
            case 5:
                displayRecords();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}