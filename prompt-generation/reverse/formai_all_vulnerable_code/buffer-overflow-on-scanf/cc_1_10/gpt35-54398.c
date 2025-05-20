//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining max size for database and maximum allowed string size
#define MAX_SIZE 100
#define MAX_STR_LEN 50

// Defining the structure for a database entry
struct Entry {
    int id;
    char name[MAX_STR_LEN];
    char address[MAX_STR_LEN];
};

// Defining the database as a global array of entries
struct Entry database[MAX_SIZE];

// Defining the current size of the database
int size = 0;

// Function to print the menu options
void printMenu() {
    printf("\n1. Add entry\n");
    printf("2. Search entry\n");
    printf("3. Remove entry\n");
    printf("4. Print all entries\n");
    printf("0. Quit\n");
}

// Function to add an entry to the database
void addEntry() {
    if(size == MAX_SIZE) {  // If database is full
        printf("Error: Database is full.\n");
        return;
    }

    // Asking for input from the user
    printf("\nEnter id: ");
    scanf("%d", &database[size].id);
    printf("Enter name: ");
    scanf("%s", database[size].name);
    printf("Enter address: ");
    scanf("%s", database[size].address);

    size++;  // Incrementing the size of the database
}

// Function to search for an entry in the database
void searchEntry() {
    int id, i;

    // Asking for input from the user
    printf("\nEnter id of the entry to search: ");
    scanf("%d", &id);

    // Searching for the entry with the given id
    for(i = 0; i < size; i++) {
        if(database[i].id == id) {
            printf("\nEntry found.\n");
            printf("Id: %d,\nName: %s,\nAddress: %s\n", database[i].id, database[i].name, database[i].address);
            return;
        }
    }

    printf("\nEntry not found.\n");  // If entry not found
}

// Function to remove an entry from the database
void removeEntry() {
    int id, i;

    // Asking for input from the user
    printf("\nEnter id of the entry to remove: ");
    scanf("%d", &id);

    // Searching for the entry with the given id
    for(i = 0; i < size; i++) {
        if(database[i].id == id) {
            // Shifting all the entries above the deleted entry downwards
            for(int j = i; j < size-1; j++) {
                database[j] = database[j+1];
            }
            size--;  // Decrementing the size of the database after deletion
            return;
        }
    }

    printf("\nEntry not found.\n");  // If entry not found
}

// Function to print all entries in the database
void printAllEntries() {
    printf("\nDatabase:\n");
    for(int i = 0; i < size; i++) {
        printf("Id: %d,\nName: %s,\nAddress: %s\n\n", database[i].id, database[i].name, database[i].address);
    }
}

int main() {
    int choice;

    do {
        printMenu();  // Printing the menu options
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEntry();
                    break;
            case 2: searchEntry();
                    break;
            case 3: removeEntry();
                    break;
            case 4: printAllEntries();
                    break;
            case 0: printf("\nGoodbye!\n");
                    break;
            default: printf("\nInvalid choice.\n");
                     break;
        }
    }while(choice != 0);

    return 0;
}