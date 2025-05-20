//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

/*
    This program simulates a simple database using C programming language.
    Users can add, remove and search entries in the database.

    Each entry is represented by a struct.
    The struct contains four fields: ID, name, age and address.
*/

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Entry;

int numOfEntries = 0;
Entry data[MAX_SIZE];

// Helper function to print message
void printMessage(char *msg) {
    printf("\n%s\n", msg);
}

// Helper function to get user input
void getUserInput(char *msg, char *input) {
    printf("%s", msg);
    scanf("%s", input);
}

// Helper function to add an entry to the database
void addEntry() {
    Entry newEntry;
    char input[MAX_SIZE];
    
    getUserInput("Enter Name: ", newEntry.name);
    getUserInput("Enter Age: ", input);
    newEntry.age = atoi(input);
    getUserInput("Enter Address: ", newEntry.address);

    // Increment ID automatically
    newEntry.id = ++numOfEntries;

    data[numOfEntries - 1] = newEntry;
    printMessage("Entry Added!");
}

// Helper function to search for an entry in the database
void searchEntry() {
    char input[MAX_SIZE];
    getUserInput("Enter ID: ", input);
    int id = atoi(input);

    int i;
    for (i = 0; i < numOfEntries; i++) {
        if (data[i].id == id) {
            printf("ID: %d\nName: %s\nAge: %d\nAddress: %s\n",
                data[i].id, data[i].name, data[i].age, data[i].address);
            return;
        }
    }
    printf("Entry not found\n");
}

// Helper function to remove an entry from the database
void removeEntry() {
    char input[MAX_SIZE];
    getUserInput("Enter ID: ", input);
    int id = atoi(input);

    int i;
    for (i = 0; i < numOfEntries; i++) {
        if (data[i].id == id) {
            int j;
            for (j = i; j < numOfEntries - 1; j++) {
                data[j] = data[j+1];
            }
            numOfEntries--;
            printMessage("Entry Removed!");
            return;
        }
    }
    printf("Entry not found\n");
}

// Helper function to print all entries in the database
void printAllEntries() {
    int i;
    for (i = 0; i < numOfEntries; i++) {
        printf("ID: %d\nName: %s\nAge: %d\nAddress: %s\n\n",
            data[i].id, data[i].name, data[i].age, data[i].address);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("Simple Database\n--------------\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Entry\n");
        printf("4. Print All Entries\n");
        printf("5. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                removeEntry();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printAllEntries();
                break;
            case 5:
                printMessage("Goodbye!");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}