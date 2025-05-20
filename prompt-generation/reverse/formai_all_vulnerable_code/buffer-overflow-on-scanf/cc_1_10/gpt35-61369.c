//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define DATABASE_SIZE 1000
#define MAX_STRING_SIZE 100

// Function prototypes
void printMenu();
void addRecord(char*** database, int* numRecords);
void deleteRecord(char*** database, int* numRecords);
void searchRecord(char** database, int numRecords);
void printDatabase(char** database, int numRecords);
void generateRandomRecords(char*** database, int* numRecords);
void freeDatabase(char** database, int numRecords);

// Main function
int main() 
{   
    char** database = (char**)malloc(DATABASE_SIZE * sizeof(char*));
    int numRecords = 0;
    srand(time(NULL));

    printf("Welcome to the post-apocalyptic database simulation.\n");

    while (1) {
        printMenu();

        // Get user selection
        int selection;
        scanf("%d", &selection);
        getchar();

        switch (selection) {
            case 1:
                addRecord(&database, &numRecords);
                break;
            case 2:
                deleteRecord(&database, &numRecords);
                break;
            case 3:
                searchRecord(database, numRecords);
                break;
            case 4:
                printDatabase(database, numRecords);
                break;
            case 5:
                generateRandomRecords(&database, &numRecords);
                break;
            case 6:
                freeDatabase(database, numRecords);
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
}

// Prints the main menu
void printMenu() 
{
    printf("\nMain Menu:\n");
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Search record\n");
    printf("4. Print database\n");
    printf("5. Generate random records\n");
    printf("6. Exit\n");
    printf("Enter selection: ");
}

// Adds a new record
void addRecord(char*** database, int* numRecords) 
{
    // Make sure we don't exceed the database size
    if (*numRecords >= DATABASE_SIZE) {
        printf("Database is full. Cannot add a new record.\n");
        return;
    }

    // Allocate memory for a new record
    char* newRecord = (char*)malloc(MAX_STRING_SIZE * sizeof(char));

    printf("Enter new record: ");
    fgets(newRecord, MAX_STRING_SIZE, stdin);

    // Add the new record to the database
    (*database)[*numRecords] = newRecord;
    (*numRecords)++;

    printf("Record added successfully.\n");
}

// Deletes a record
void deleteRecord(char*** database, int* numRecords) 
{
    printf("Enter index to delete: ");

    int indexToDelete;
    scanf("%d", &indexToDelete);
    getchar();

    // Make sure the index is within range
    if (indexToDelete < 0 || indexToDelete >= *numRecords) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Free memory for the deleted record
    free((*database)[indexToDelete]);

    // Shift all records after the deleted record to the left
    for (int i = indexToDelete; i < *numRecords - 1; i++) {
        (*database)[i] = (*database)[i + 1];
    }

    (*numRecords)--;
    printf("Record deleted successfully.\n");
}

// Searches for a record
void searchRecord(char** database, int numRecords) 
{
    printf("Enter search query: ");

    char searchQuery[MAX_STRING_SIZE];
    fgets(searchQuery, MAX_STRING_SIZE, stdin);

    int found = 0;

    for (int i = 0; i < numRecords; i++) {
        if (strstr(database[i], searchQuery) != NULL) {
            printf("%d: %s", i, database[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching records found.\n");
    }
}

// Prints the entire database
void printDatabase(char** database, int numRecords) 
{
    printf("Current database contents:\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%d: %s", i, database[i]);
    }
}

// Generates random records
void generateRandomRecords(char*** database, int* numRecords) 
{
    int numNewRecords;
    printf("Enter number of new records to generate: ");
    scanf("%d", &numNewRecords);
    getchar();

    // Make sure we don't exceed the database size
    if (*numRecords + numNewRecords > DATABASE_SIZE) {
        printf("Cannot generate that many records. Database will exceed its size limit.\n");
        return;
    }

    // Generate new random records
    for (int i = 0; i < numNewRecords; i++) {
        char* newRecord = (char*)malloc(MAX_STRING_SIZE * sizeof(char));

        // Generate a random string
        for (int j = 0; j < MAX_STRING_SIZE - 1; j++) {
            newRecord[j] = (rand() % 26) + 'a';
        }

        newRecord[MAX_STRING_SIZE - 1] = '\0';

        // Add the new record to the database
        (*database)[*numRecords] = newRecord;
        (*numRecords)++;
    }

    printf("Random records generated successfully.\n");
}

// Frees all memory used by the database
void freeDatabase(char** database, int numRecords) 
{
    for (int i = 0; i < numRecords; i++) {
        free(database[i]);
    }

    free(database);
}