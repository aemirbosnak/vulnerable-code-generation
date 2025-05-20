//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: innovative
/*
 * Warehouse Management System
 *
 * A unique C program to manage a warehouse
 *
 * Developed by: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the struct for storing the warehouse inventory
struct inventory {
    int id;
    char name[50];
    int quantity;
};

// Function to print the inventory
void print_inventory(struct inventory *inventory, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("ID: %d\tName: %s\tQuantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

// Function to add a new item to the inventory
void add_item(struct inventory *inventory, int num_items) {
    int id;
    char name[50];
    int quantity;

    // Prompt the user for the item details
    printf("Enter the ID, name, and quantity of the item:\n");
    scanf("%d %s %d", &id, name, &quantity);

    // Check if the item already exists in the inventory
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            printf("Item already exists in the inventory. Update the quantity instead.\n");
            return;
        }
    }

    // Add the new item to the inventory
    inventory[num_items].id = id;
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    num_items++;
}

// Function to update the quantity of an item in the inventory
void update_quantity(struct inventory *inventory, int num_items) {
    int id;
    int quantity;

    // Prompt the user for the ID and the new quantity
    printf("Enter the ID of the item and the new quantity:\n");
    scanf("%d %d", &id, &quantity);

    // Find the item in the inventory and update its quantity
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = quantity;
            break;
        }
    }
}

// Function to remove an item from the inventory
void remove_item(struct inventory *inventory, int num_items) {
    int id;

    // Prompt the user for the ID of the item to remove
    printf("Enter the ID of the item to remove:\n");
    scanf("%d", &id);

    // Find the item in the inventory and remove it
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            // Remove the item from the inventory
            for (int j = i; j < num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_items--;
            break;
        }
    }
}

int main() {
    // Initialize the inventory array
    struct inventory inventory[100];
    int num_items = 0;

    // Add items to the inventory
    add_item(inventory, num_items);
    add_item(inventory, num_items);
    add_item(inventory, num_items);

    // Update the quantity of an item
    update_quantity(inventory, num_items);

    // Remove an item from the inventory
    remove_item(inventory, num_items);

    // Print the inventory
    print_inventory(inventory, num_items);

    return 0;
}