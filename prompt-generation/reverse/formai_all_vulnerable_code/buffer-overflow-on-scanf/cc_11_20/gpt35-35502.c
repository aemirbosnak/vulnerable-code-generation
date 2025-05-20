//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the struct for the database entry
struct Entry {
    char name[20];
    int age;
    char address[40];
};

int main() {
    int choice, num_entries = 0;
    struct Entry database[MAX_SIZE];

    // Loop to present menu and get user input
    while (1) {
        printf("\nDatabase Options:\n");
        printf("1. Add Entry\n");
        printf("2. Edit Entry\n");
        printf("3. Remove Entry\n");
        printf("4. View All Entries\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to perform actions based on user input
        switch (choice) {
            case 1:
                // Add new entry to the database
                if (num_entries >= MAX_SIZE) {
                    printf("\nError: Database is Full\n");
                    break;
                }
                struct Entry new_entry;
                printf("\nEnter Name: ");
                scanf("%s", new_entry.name);
                printf("Enter Age: ");
                scanf("%d", &new_entry.age);
                printf("Enter Address: ");
                scanf("%s", new_entry.address);
                database[num_entries++] = new_entry;
                printf("\nNew Entry added successfully\n");
                break;

            case 2:
                // Edit an existing entry
                if (num_entries == 0) {
                    printf("\nError: Database is Empty\n");
                    break;
                }
                printf("\nEnter the name of the entry to edit: ");
                char edit_name[20];
                scanf("%s", edit_name);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(database[i].name, edit_name) == 0) {
                        printf("\n%s's age is %d and address is %s\n", database[i].name, database[i].age, database[i].address);
                        printf("\nEnter new age: ");
                        scanf("%d", &database[i].age);
                        printf("Enter new address: ");
                        scanf("%s", database[i].address);
                        printf("\nEntry updated successfully\n");
                        break;
                    }
                    if (i == num_entries - 1) {
                        printf("\nError: Entry not found\n");
                    }
                }
                break;

            case 3:
                // Remove an existing entry
                if (num_entries == 0) {
                    printf("\nError: Database is Empty\n");
                    break;
                }
                printf("\nEnter the name of the entry to remove: ");
                char remove_name[20];
                scanf("%s", remove_name);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(database[i].name, remove_name) == 0) {
                        for (int j = i; j < num_entries - 1; j++) {
                            database[j] = database[j + 1];
                        }
                        num_entries--;
                        printf("\nEntry removed successfully\n");
                        break;
                    }
                    if (i == num_entries - 1) {
                        printf("\nError: Entry not found\n");
                    }
                }
                break;

            case 4:
                // Display all entries in the database
                if (num_entries == 0) {
                    printf("\nNo Entries Found\n");
                    break;
                }
                printf("\nDatabase Entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%d. Name: %s, Age: %d, Address: %s\n", i + 1, database[i].name, database[i].age, database[i].address);
                }
                break;

            case 5:
                // Exit the program
                printf("\nExiting Database\n");
                exit(0);

            default:
                // Invalid entry
                printf("\nError: Invalid Choice\n");
        }
    }
    return 0;
}