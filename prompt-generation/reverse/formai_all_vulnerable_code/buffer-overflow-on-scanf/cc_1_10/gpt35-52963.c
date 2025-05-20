//FormAI DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our Database
struct Database {
    int id;
    char name[50];
    int age;
};

// Declare function prototypes
void addRecord();
void displayRecords();
void searchRecord();
void deleteRecord();

// Define a global array of struct Database type
struct Database records[100];
int numRecords = 0;

int main() {
    int option = 0;
    do {
        // Print menu
        printf("\n======== Database Simulation ========\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        
        // Read user option
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); // consume newline
        
        // Do corresponding action based on user's option
        switch (option) {
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
                deleteRecord();
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid Option, Please Try Again.\n\n");
                break;
        }
    } while (option != 5);
    return 0;
}

void addRecord() {
    // Ask user for input
    printf("\nEnter the following details:\n");
    printf("  ID   : ");
    scanf("%d", &records[numRecords].id);
    getchar(); // consume newline
    printf("  Name : ");
    fgets(records[numRecords].name, 50, stdin);
    strtok(records[numRecords].name, "\n"); // remove newline character
    printf("  Age  : ");
    scanf("%d", &records[numRecords].age);
    getchar(); // consume newline
    
    // Increment number of records
    numRecords++;
    printf("\nRecord Added Successfully!\n\n");
}

void displayRecords() {
    // Check if there are any records to display
    if (numRecords == 0) {
        printf("\nThere are currently no records to display.\n\n");
        return;
    }
    
    // Print header row
    printf("\nID\tName\t\tAge\n");
    
    // Loop through all records and print details
    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t\t%d\n", records[i].id, records[i].name, records[i].age);
    }
    printf("\n");
}

void searchRecord() {
    // Check if there are any records to search
    if (numRecords == 0) {
        printf("\nThere are currently no records to search.\n\n");
        return;
    }
    
    // Ask user for input
    printf("\nEnter the ID of the record to search: ");
    int searchID;
    scanf("%d", &searchID);
    getchar(); // consume newline
    
    // Loop through all records to find the matching ID
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == searchID) {
            printf("\nID   : %d\n", records[i].id);
            printf("Name : %s\n", records[i].name);
            printf("Age  : %d\n\n", records[i].age);
            return;
        }
    }
    printf("\nNo matching record found for ID %d.\n\n", searchID);
}

void deleteRecord() {
    // Check if there are any records to delete
    if (numRecords == 0) {
        printf("\nThere are currently no records to delete.\n\n");
        return;
    }
    
    // Ask user for input
    printf("\nEnter the ID of the record to delete: ");
    int deleteID;
    scanf("%d", &deleteID);
    getchar(); // consume newline
    
    // Loop through all records to find the matching ID
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == deleteID) {
            // Shift all records after the deleted one to the left by 1
            for (int j = i + 1; j < numRecords; j++) {
                records[j - 1] = records[j];
            }
            // Decrement number of records
            numRecords--;
            printf("\nRecord with ID %d has been deleted successfully.\n\n", deleteID);
            return;
        }
    }
    printf("\nNo matching record found for ID %d.\n\n", deleteID);
}