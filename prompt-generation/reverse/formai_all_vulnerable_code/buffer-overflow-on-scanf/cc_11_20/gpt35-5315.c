//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent the database
typedef struct {
    char name[50];
    int value;
} Item;

int main() {

    // Define an array of items
    Item items[100];
    int num_items = 0;

    // Main menu loop
    while (1) {

        // Print the main menu options
        printf("\nDatabase Simulation\n=====================\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Item\n");
        printf("4. Exit\n");

        // Get the user's choice
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Perform an action based on the user's choice
        switch (choice) {

            // Add a new item to the database
            case 1: {
                // Make sure there is space in the array
                if (num_items >= 100) {
                    printf("Error: Maximum number of items reached\n");
                    continue;
                }

                // Get the item name and value from the user
                char name[50];
                int value;
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item value: ");
                scanf("%d", &value);

                // Add the item to the array and increment the count
                strcpy(items[num_items].name, name);
                items[num_items].value = value;
                num_items++;

                printf("Item added to database\n");
                break;
            }

            // Remove an item from the database
            case 2: {
                // Make sure there are items in the array
                if (num_items == 0) {
                    printf("Error: No items in database\n");
                    continue;
                }

                // Get the item name to remove from the user
                char name[50];
                printf("Enter item name to remove: ");
                scanf("%s", name);

                // Find the item to remove and shift the remaining items down
                int i, removed = 0;
                for (i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, name) == 0) {
                        removed = 1;
                    }
                    if (removed) {
                        strcpy(items[i].name, items[i+1].name);
                        items[i].value = items[i+1].value;
                    }
                }

                // Decrement the count if an item was removed
                if (removed) {
                    num_items--;
                    printf("Item removed from database\n");
                } else {
                    printf("Error: Item not found in database\n");
                }

                break;
            }

            // View an item in the database
            case 3: {
                // Make sure there are items in the array
                if (num_items == 0) {
                    printf("Error: No items in database\n");
                    continue;
                }

                // Get the item name to view from the user
                char name[50];
                printf("Enter item name to view: ");
                scanf("%s", name);

                // Find and print the item
                int i, found = 0;
                for (i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, name) == 0) {
                        printf("Item Name: %s\n", items[i].name);
                        printf("Item Value: %d\n", items[i].value);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Error: Item not found in database\n");
                }
                break;
            }

            // Exit the program
            case 4: {
                printf("Exiting...\n");
                return 0;
            }

            default:
                printf("Error: Invalid choice\n");
        }
    }
}