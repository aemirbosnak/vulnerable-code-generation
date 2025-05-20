//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct representing a database record
struct Record {
    int id;
    char name[50];
    char address[100];
    float salary;
};

// Function to add a new record to the database
void addRecord(struct Record** records, int* size) {
    // Increase the size of the records array
    *size += 1;
    *records = (struct Record*)realloc(*records, *size * sizeof(struct Record));
    
    // Get the details of the new record from the user
    struct Record* newRecord = &((*records)[*size - 1]);
    newRecord->id = *size;
    printf("Enter the name of the employee: ");
    scanf("%s", &(newRecord->name));
    printf("Enter the address of the employee: ");
    scanf("%s", &(newRecord->address));
    printf("Enter the salary of the employee: ");
    scanf("%f", &(newRecord->salary));
    
    printf("Record added successfully.\n");
}

// Function to display all the records in the database
void displayRecords(struct Record* records, int size) {
    printf("-----------------------------------------\n");
    printf("ID\tName\tAddress\tSalary\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%f\n", records[i].id, records[i].name, records[i].address, records[i].salary);
    }
    printf("-----------------------------------------\n");
}

int main() {
    // Declare and initialize the records array
    int size = 0;
    struct Record* records = (struct Record*)malloc(size * sizeof(struct Record));
    
    // Display the menu and get the user's choice
    int choice;
    while (1) {
        printf("1. Add new record.\n");
        printf("2. Display all records.\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(&records, &size);
                break;
            case 2:
                displayRecords(records, size);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}