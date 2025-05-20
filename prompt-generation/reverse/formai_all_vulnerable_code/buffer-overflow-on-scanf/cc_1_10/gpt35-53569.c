//FormAI DATASET v1.0 Category: Database querying ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for database entries
struct database_entry {
    int id;
    char name[50];
    char email[50];
    int age;
};

// Define function to add a new entry to the database
void add_entry(struct database_entry* database, int* num_entries) {
    // Prompt user for input
    printf("Enter name: ");
    scanf("%s", database[*num_entries].name);

    printf("Enter email: ");
    scanf("%s", database[*num_entries].email);

    printf("Enter age: ");
    scanf("%d", &database[*num_entries].age);

    // Assign new ID based on current number of entries
    database[*num_entries].id = *num_entries + 1;

    // Increment number of entries
    *num_entries += 1;

    // Print message to confirm entry was added
    printf("New entry added to database.\n");
}

// Define function to search for an entry by ID
void search_by_id(struct database_entry* database, int num_entries) {
    // Prompt user for input
    printf("Enter ID to search for: ");
    int search_id;
    scanf("%d", &search_id);

    // Loop through entries in the database
    for (int i = 0; i < num_entries; i++) {
        // If a matching ID is found, print entry details and return
        if (database[i].id == search_id) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Email: %s\n", database[i].email);
            printf("Age: %d\n", database[i].age);
            return;
        }
    }

    // If no matching ID is found, print an error message
    printf("Entry not found.\n");
}

// Define function to print all entries in the database
void print_database(struct database_entry* database, int num_entries) {
    // Loop through all entries in the database and print their details
    for (int i = 0; i < num_entries; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Email: %s\n", database[i].email);
        printf("Age: %d\n", database[i].age);
        printf("\n");
    }
}

int main() {
    // Create empty array to store database entries
    struct database_entry database[100];

    // Initialize number of entries to 0
    int num_entries = 0;

    // Display initial menu to user
    printf("Welcome to the database program.\n");
    printf("Please select an option:\n");
    printf("1. Add a new entry\n");
    printf("2. Search for an entry by ID\n");
    printf("3. Print the entire database\n");
    printf("4. Quit\n");

    // Loop until user chooses to quit
    int choice = 0;
    while (choice != 4) {
        // Prompt user for choice
        scanf("%d", &choice);

        // Call appropriate function based on user's choice
        switch (choice) {
            case 1:
                add_entry(database, &num_entries);
                break;
            case 2:
                search_by_id(database, num_entries);
                break;
            case 3:
                print_database(database, num_entries);
                break;
            case 4:
                // Do nothing, loop will exit
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Display menu again for user to choose another option
        if (choice != 4) {
            printf("Please select another option:\n");
            printf("1. Add a new entry\n");
            printf("2. Search for an entry by ID\n");
            printf("3. Print the entire database\n");
            printf("4. Quit\n");
        }
    }

    // Print goodbye message and exit program
    printf("Goodbye!\n");
    return 0;
}