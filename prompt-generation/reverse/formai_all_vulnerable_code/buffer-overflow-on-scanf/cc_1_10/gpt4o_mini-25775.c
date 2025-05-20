//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
} Record;

Record records[MAX_RECORDS];
int recordCount = 0;

// Function to create a new record
void createRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }
    
    Record newRecord;
    newRecord.id = recordCount + 1;  // Simple ID assignment

    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter address: ");
    scanf(" %[^\n]", newRecord.address); // to read string with spaces

    records[recordCount] = newRecord;
    recordCount++;
    printf("Record added successfully!\n");
}

// Function to display all records
void displayRecords() {
    if (recordCount == 0) {
        printf("No records found.\n");
        return;
    }
    
    printf("\n--- Records List ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Address: %s\n", records[i].id, records[i].name, records[i].address);
    }
    printf("---------------------\n");
}

// Function to search records by name
void searchRecord() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("Record found: ID: %d, Name: %s, Address: %s\n", records[i].id, records[i].name, records[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

// Function to save records to a file
void saveRecords() {
    FILE *file = fopen("records.dat", "wb");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    fwrite(records, sizeof(Record), recordCount, file);
    fclose(file);
    printf("Records saved to file successfully!\n");
}

// Function to load records from a file
void loadRecords() {
    FILE *file = fopen("records.dat", "rb");
    if (!file) {
        printf("No saved records found. Starting fresh.\n");
        return;
    }

    recordCount = fread(records, sizeof(Record), MAX_RECORDS, file);
    fclose(file);
    printf("Records loaded successfully! Total records: %d\n", recordCount);
}

// Main function to run the program
int main() {
    loadRecords();  // Load any existing records at start

    int choice;
    do {
        printf("\n--- Simple Database Indexing System ---\n");
        printf("1. Create Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                saveRecords();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}