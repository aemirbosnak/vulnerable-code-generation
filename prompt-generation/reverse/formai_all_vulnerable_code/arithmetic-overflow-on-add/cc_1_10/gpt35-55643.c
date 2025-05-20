//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>

// defining the maximum capacity of the warehouse
#define MAX_CAPACITY 100

int main() {
    // declaring an array to store the quantities of each item in the warehouse
    int inventory[MAX_CAPACITY] = {0};

    // declaring variables to keep track of the number of items in the warehouse and the capacity
    int numItems = 0;
    int capacity = MAX_CAPACITY;

    // declaring variables to hold the user's input
    int choice, item, quantity;

    // loop to display the main menu and handle the user's input
    while (1) {
        // displaying the menu options to the user
        printf("Warehouse Management System\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Check inventory\n");
        printf("4. Exit\n\n");

        // prompting the user for their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // handling the user's choice
        switch (choice) {
            case 1: // add item to inventory
                if (numItems >= capacity) {
                    printf("Warehouse is at maximum capacity.\n\n");
                } else {
                    // prompting the user for the item and quantity to add
                    printf("Enter item number to add: ");
                    scanf("%d", &item);
                    printf("Enter quantity to add: ");
                    scanf("%d", &quantity);

                    // updating the inventory and number of items
                    inventory[item] += quantity;
                    numItems += quantity;

                    // printing confirmation message
                    printf("%d units of item %d added to inventory.\n\n", quantity, item);
                }
                break;

            case 2: // remove item from inventory
                // prompting the user for the item and quantity to remove
                printf("Enter item number to remove: ");
                scanf("%d", &item);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);

                if (inventory[item] < quantity) {
                    // not enough of the item is in the inventory
                    printf("Error: There are only %d units of item %d in the inventory.\n\n", inventory[item], item);
                } else {
                    // updating the inventory and number of items
                    inventory[item] -= quantity;
                    numItems -= quantity;

                    // printing confirmation message
                    printf("%d units of item %d removed from inventory.\n\n", quantity, item);
                }
                break;

            case 3: // check inventory
                printf("Current inventory:\n");
                for (int i = 0; i < MAX_CAPACITY; i++) {
                    if (inventory[i] > 0) {
                        printf("Item %d: %d units\n", i, inventory[i]);
                    }
                }
                printf("\n");
                break;

            case 4: // exit
                printf("Exiting program.\n");
                return 0;

            default: // invalid choice
                printf("Invalid choice. Please enter 1-4.\n\n");
        }
    }

    return 0;
}