//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Define the structure for the items in the inventory
typedef struct {
    char name[50];
    int quantity;
    float price;
} inventory_item;

// Define the inventory array
inventory_item inventory[MAX_ITEMS];

// Define the number of items in the inventory
int num_items = 0;

// Function to add an item to the inventory
void add_item() {
    // Check if the inventory is full
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full, cannot add new items.\n");
        return;
    }

    // Get the item details from the user
    printf("Enter the item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter the quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("Enter the price: ");
    scanf("%f", &inventory[num_items].price);

    // Increment the number of items in the inventory
    num_items++;

    printf("Item added to the inventory.\n");
}

// Function to remove an item from the inventory
void remove_item() {
    // Check if the inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty, cannot remove items.\n");
        return;
    }

    // Get the item name from the user
    char name[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);

    // Search for the item in the inventory
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the item is not found, print an error message
    if (index == -1) {
        printf("Item not found in the inventory.\n");
        return;
    }

    // Shift the items after the removed item by 1 position to the left
    for (int i = index; i < num_items - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the number of items in the inventory
    num_items--;

    printf("Item removed from the inventory.\n");
}

// Function to search for an item in the inventory
void search_item() {
    // Check if the inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty, cannot search items.\n");
        return;
    }

    // Get the item name from the user
    char name[50];
    printf("Enter the name of the item to search for: ");
    scanf("%s", name);

    // Search for the item in the inventory
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the item is not found, print an error message
    if (index == -1) {
        printf("Item not found in the inventory.\n");
        return;
    }

    // Print the details of the item
    printf("Name: %s\n", inventory[index].name);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: %.2f\n", inventory[index].price);
}

// Function to display the inventory
void display_inventory() {
    // Check if the inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty, nothing to display.\n");
        return;
    }

    // Print the header
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    // Print the details of each item in the inventory
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to display the menu and get the user's choice
int get_choice() {
    int choice;
    printf("\n");
    printf("1. Add item to inventory\n");
    printf("2. Remove item from inventory\n");
    printf("3. Search for item in inventory\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    int choice;

    do {
        choice = get_choice();

        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            remove_item();
            break;
        case 3:
            search_item();
            break;
        case 4:
            display_inventory();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}