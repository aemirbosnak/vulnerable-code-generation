//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
// Cheerful Database Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10 // Maximum number of data entries in the database

// Struct to store each data entry
typedef struct {
    char name[20]; // Name of the person
    int age; // Age of the person
    float height; // Height of the person
} Data;

// Global variables
Data database[MAX_SIZE]; // Array to store the data entries
int num_entries = 0; // Number of entries currently in the database

// Function to add a new data entry to the database
void add_entry() {
    if (num_entries >= MAX_SIZE) {
        printf("Sorry, the database is full!\n");
        return;
    }

    // Create a new data entry and add it to the database
    Data new_entry;

    printf("Enter the name: ");
    scanf("%s", new_entry.name);

    printf("Enter the age: ");
    scanf("%d", &new_entry.age);

    printf("Enter the height: ");
    scanf("%f", &new_entry.height);

    database[num_entries] = new_entry;
    num_entries++;

    printf("Entry added successfully!\n");
}

// Function to view all the data entries in the database
void view_entries() {
    if (num_entries == 0) {
        printf("The database is empty!\n");
        return;
    }

    printf("Name\tAge\tHeight\n");

    for (int i = 0; i < num_entries; i++) {
        Data entry = database[i];
        printf("%s\t%d\t%.2f\n", entry.name, entry.age, entry.height);
    }
}

// Function to search for a data entry in the database by name
void search_entry() {
    if (num_entries == 0) {
        printf("The database is empty!\n");
        return;
    }

    char name[20];
    printf("Enter the name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        Data entry = database[i];
        if (strcmp(entry.name, name) == 0) {
            printf("Name\tAge\tHeight\n");
            printf("%s\t%d\t%.2f\n", entry.name, entry.age, entry.height);
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    printf("Welcome to the Cheerful Database Simulation!\n");

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Goodbye! Have a cheerful day!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}