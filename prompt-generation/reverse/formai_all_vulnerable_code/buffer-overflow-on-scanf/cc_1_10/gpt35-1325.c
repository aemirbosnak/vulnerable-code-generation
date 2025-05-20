//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_ITEMS 1000

// Define our data structure for each inventory item
struct inventory_item {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
};

// Initialize our inventory array and the number of items in it
struct inventory_item inventory[MAX_ITEMS];
int num_items = 0;

// Function prototypes
void add_item();
void remove_item();
void display_inventory();

int main() {
    // Variable to hold user's choice
    char choice;

    // Loop until user chooses to exit
    while (1) {
        // Display menu options
        printf("Enter a choice:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit Program\n");

        // Get user's choice
        scanf(" %c", &choice);

        // Handle user's choice
        switch (choice) {
            case '1':
                add_item();
                break;
            case '2':
                remove_item();
                break;
            case '3':
                display_inventory();
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_item() {
    // Check if inventory is full
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Get user input for new item
    struct inventory_item item;
    printf("Enter item name: ");
    scanf(" %[^\n]s", item.name);
    printf("Enter item description: ");
    scanf(" %[^\n]s", item.description);
    printf("Enter item quantity: ");
    scanf(" %d", &item.quantity);

    // Add item to inventory and increment item counter
    inventory[num_items++] = item;

    printf("Item added successfully.\n");
}

void remove_item() {
    // Check if inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty. Cannot remove any items.\n");
        return;
    }

    // Get user input for item to remove
    char item_name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]s", item_name);

    // Loop through inventory to find matching item
    int item_index;
    int found_item = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            item_index = i;
            found_item = 1;
            break;
        }
    }

    // If item not found, print error message and return to menu
    if (!found_item) {
        printf("Item not found in inventory.\n");
        return;
    }

    // Shift remaining items to fill gap
    for (int i = item_index; i < num_items - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    // Decrement item counter
    num_items--;

    printf("Item removed successfully.\n");
}

void display_inventory() {
    // Check if inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    // Display inventory header
    printf("%-30s %-30s %-10s\n", "Item", "Description", "Quantity");

    // Loop through inventory and display each item
    for (int i = 0; i < num_items; i++) {
        printf("%-30s %-30s %-10d\n", inventory[i].name, inventory[i].description, inventory[i].quantity);
    }
}