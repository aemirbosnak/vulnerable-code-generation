//FormAI DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_RECORDS 1000
#define MAX_STRING_LENGTH 50

// Declare struct for database record
struct Record {
    int id;
    char name[MAX_STRING_LENGTH];
    char phone_number[MAX_STRING_LENGTH];
};

// Declare global variables
int num_records = 0;
struct Record database[MAX_RECORDS];

// Declare function prototypes
void addRecord();
void searchRecord();

int main() {
    int choice;
    printf("Welcome to the Database Indexing System!\n\n");
    do {
        printf("Please choose an option:\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                // Do nothing, exit program
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void addRecord() {
    // Check if there is room in database for new record
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n\n");
        return;
    }

    // Get user input for new record
    int id;
    char name[MAX_STRING_LENGTH];
    char phone_number[MAX_STRING_LENGTH];
    printf("\nEnter the record ID: ");
    scanf("%d", &id);
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the phone number: ");
    scanf("%s", phone_number);

    // Add new record to database
    database[num_records].id = id;
    strcpy(database[num_records].name, name);
    strcpy(database[num_records].phone_number, phone_number);
    num_records++;

    printf("\nRecord added successfully.\n\n");
}

void searchRecord() {
    // Get user input for search term
    char search_term[MAX_STRING_LENGTH];
    printf("\nEnter a name to search for: ");
    scanf("%s", search_term);

    // Search for matching records
    printf("\nMatching records:\n");
    for (int i = 0; i < num_records; i++) {
        if (strstr(database[i].name, search_term) != NULL) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Phone number: %s\n\n", database[i].phone_number);
        }
    }
}