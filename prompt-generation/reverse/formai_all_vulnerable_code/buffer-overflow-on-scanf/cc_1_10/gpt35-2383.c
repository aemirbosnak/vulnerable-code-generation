//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
// "The Case of the Missing Database" - a Sherlock Holmes style C database simulation example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to hold the data of each entry in the database
typedef struct {
    int id;
    char name[50];
    char occupation[50];
} Entry;

// Function to add a new entry to the database
void addEntry(Entry* database, int* numOfEntries) {
    Entry newEntry;

    // Getting the details of the new entry from the user
    printf("\nEnter the ID of the new entry: ");
    scanf("%d", &newEntry.id);
    printf("\nEnter the name of the new entry: ");
    scanf("%s", newEntry.name);
    printf("\nEnter the occupation of the new entry: ");
    scanf("%s", newEntry.occupation);

    // Adding the new entry to the database
    database[*numOfEntries] = newEntry;
    (*numOfEntries)++;
    printf("\nEntry added successfully.\n");
}

// Function to search for an entry in the database by ID
void searchByID(Entry* database, int numOfEntries) {
    int searchID;
    int found = 0;

    // Getting the ID to search for from the user
    printf("\nEnter the ID to search for: ");
    scanf("%d", &searchID);

    // Looping through the database to find the entry with the given ID
    for (int i = 0; i < numOfEntries; i++) {
        if (database[i].id == searchID) {
            printf("\nID: %d\nName: %s\nOccupation: %s\n", database[i].id, database[i].name, database[i].occupation);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo entry with the given ID found.\n");
    }
}

// Function to delete an entry from the database by ID
void deleteByID(Entry* database, int* numOfEntries) {
    int deleteID;
    int found = 0;

    // Getting the ID of the entry to delete from the user
    printf("\nEnter the ID of the entry to delete: ");
    scanf("%d", &deleteID);

    // Looping through the database to find the entry with the given ID and delete it
    for (int i = 0; i < *numOfEntries; i++) {
        if (database[i].id == deleteID) {
            for (int j = i; j < (*numOfEntries) - 1; j++) {
                database[j] = database[j + 1];
            }
            (*numOfEntries)--;
            found = 1;
            printf("\nEntry deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nNo entry with the given ID found.\n");
    }
}

// Function to display all entries in the database
void displayAll(Entry* database, int numOfEntries) {
    printf("\n--- All Entries ---\n");
    for (int i = 0; i < numOfEntries; i++) {
        printf("\nID: %d\nName: %s\nOccupation: %s\n", database[i].id, database[i].name, database[i].occupation);
    }
}

// Main function
int main() {
    // Initializing the database as an array of Entries
    Entry database[50];
    int numOfEntries = 0;
    int choice;

    // Displaying the welcome message and menu options
    printf("\nWelcome to the database simulation program.\n");
    printf("\nMenu:\n1. Add new entry\n2. Search by ID\n3. Delete by ID\n4. Display all entries\n5. Exit");

    // Looping until the user chooses to exit
    while (1) {
        // Getting the user's choice from the menu
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(database, &numOfEntries);
                break;
            case 2:
                searchByID(database, numOfEntries);
                break;
            case 3:
                deleteByID(database, &numOfEntries);
                break;
            case 4:
                displayAll(database, numOfEntries);
                break;
            case 5:
                // Exiting the program
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}