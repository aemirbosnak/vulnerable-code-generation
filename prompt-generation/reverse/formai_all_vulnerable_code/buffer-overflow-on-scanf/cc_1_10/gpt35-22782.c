//FormAI DATASET v1.0 Category: Database simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Maximum number of records which can be stored in the database
#define MAX_RECORDS 100

// Structure to store the record fields
struct Record {
    int id; // Record ID, unique identifier
    char name[50]; // Name of the record
    int age; // Age of the person
};

// Function prototypes
void addRecord();
void deleteRecord();
void searchRecord();
void printDatabase();
void saveDatabase();
void loadDatabase();
void clearDatabase();
void printMenu();

// The database structure to store all the records
struct Record database[MAX_RECORDS];

// The number of records currently in the database
int recordCount = 0;

int main() {
    int choice;
    // Display the main menu and process user input until they choose to exit
    do {
        printMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                printDatabase();
                break;
            case 5:
                saveDatabase();
                break;
            case 6:
                loadDatabase();
                break;
            case 7:
                clearDatabase();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 8);
    return 0;
}

// Function to display the main menu
void printMenu() {
    printf("\nMain Menu\n");
    printf("1. Add a new record\n");
    printf("2. Delete a record\n");
    printf("3. Search for a record\n");
    printf("4. Print all records\n");
    printf("5. Save database to file\n");
    printf("6. Load database from file\n");
    printf("7. Clear the database\n");
    printf("8. Exit\n");
}

// Function to add a new record to the database
void addRecord() {
    int id, age, i;
    char name[50];
    // Check if there is space left in the database
    if(recordCount < MAX_RECORDS) {
        // Get values for the new record
        printf("Enter a unique ID for the new record: ");
        scanf("%d", &id);
        // Check if the ID already exists
        for(i = 0; i < recordCount; i++) {
            if(database[i].id == id) {
                printf("Error: Record with this ID already exists.\n");
                return;
            }
        }
        printf("Enter the name for the new record: ");
        scanf("%s", name);
        printf("Enter the age for the new record: ");
        scanf("%d", &age);
        // Create the new record and add it to the database
        struct Record newRecord = {id, name, age};
        database[recordCount] = newRecord;
        recordCount++;
        printf("Added new record to the database.\n");
    } else {
        printf("Error: Database is full and cannot add new records.\n");
    }
}

// Function to delete a record from the database
void deleteRecord() {
    int id, i, found = 0;
    // Get the ID of the record to delete
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);
    // Find the record with the given ID
    for(i = 0; i < recordCount; i++) {
        if(database[i].id == id) {
            // Delete the record by shifting all subsequent records back by one
            for(; i < recordCount - 1; i++) {
                database[i] = database[i+1];
            }
            recordCount--;
            printf("Deleted record with ID %d from the database.\n", id);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Error: Record with ID %d not found in the database.\n", id);
    }
}

// Function to search for a record by ID and print its details
void searchRecord() {
    int id, i, found = 0;
    // Get the ID of the record to search for
    printf("Enter the ID of the record to search for: ");
    scanf("%d", &id);
    // Search for the record with the given ID and print its details if found
    for(i = 0; i < recordCount; i++) {
        if(database[i].id == id) {
            printf("Record with ID %d:\n", id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Error: Record with ID %d not found in the database.\n", id);
    }
}

// Function to print the details of all records in the database
void printDatabase() {
    int i;
    if(recordCount == 0) {
        printf("Database is empty.\n");
    } else {
        printf("Printing all records in the database:\n");
        for(i = 0; i < recordCount; i++) {
            printf("Record %d:\n", i+1);
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("\n");
        }
    }
}

// Function to save the database to a file
void saveDatabase() {
    char fileName[50];
    int i;
    FILE *filePointer;
    // Get the file name from the user
    printf("Enter the name of the file to save the database to: ");
    scanf("%s", fileName);
    // Open the file for writing
    filePointer = fopen(fileName, "w");
    if(filePointer == NULL) {
        printf("Error: Cannot open file %s for writing.\n", fileName);
        return;
    }
    // Write each record to the file
    for(i = 0; i < recordCount; i++) {
        fprintf(filePointer, "%d,%s,%d\n", database[i].id, database[i].name, database[i].age);
    }
    fclose(filePointer);
    printf("Saved database to file %s.\n", fileName);
}

// Function to load the database from a file
void loadDatabase() {
    char fileName[50], line[100], *token;
    int id, age;
    char name[50];
    FILE *filePointer;
    // Get the file name from the user
    printf("Enter the name of the file to load the database from: ");
    scanf("%s", fileName);
    // Open the file for reading
    filePointer = fopen(fileName, "r");
    if(filePointer == NULL) {
        printf("Error: Cannot open file %s for reading.\n", fileName);
        return;
    }
    // Clear any existing records from the database
    clearDatabase();
    // Read the contents of the file and add them as new records to the database
    while(fgets(line, 100, filePointer) != NULL) {
        // Parse the record fields from the line
        token = strtok(line, ",");
        id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(name, token);
        token = strtok(NULL, ",");
        age = atoi(token);
        // Add the record to the database
        struct Record newRecord = {id, name, age};
        database[recordCount] = newRecord;
        recordCount++;
    }
    fclose(filePointer);
    printf("Loaded database from file %s.\n", fileName);
}

// Function to clear all records from the database
void clearDatabase() {
    recordCount = 0;
    printf("Cleared all records from the database.\n");
}