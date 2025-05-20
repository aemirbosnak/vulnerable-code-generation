//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse items
typedef struct Item {
    char *name;
    int quantity;
    float price;
} Item;

// Warehouse inventory
Item inventory[] = {
    {"Apples", 100, 0.50},
    {"Bananas", 50, 0.75},
    {"Oranges", 75, 1.00},
    {"Grapes", 25, 1.25},
    {"Strawberries", 15, 1.50}
};

// Warehouse size
#define WAREHOUSE_SIZE sizeof(inventory) / sizeof(Item)

// Print a happy welcome message
void welcome() {
    printf("Welcome to our warehouse! We're glad you're here!\n");
}

// Print the warehouse inventory
void print_inventory() {
    printf("Here's what we have in stock:\n");
    for (int i = 0; i < WAREHOUSE_SIZE; i++) {
        printf("%s: %d units ($%.2f each)\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Add an item to the inventory
void add_item(char *name, int quantity, float price) {
    // Check if the item already exists
    for (int i = 0; i < WAREHOUSE_SIZE; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            printf("Added %d units of %s to the inventory.\n", quantity, name);
            return;
        }
    }

    // Add the new item to the inventory
    Item new_item = {name, quantity, price};
    inventory[WAREHOUSE_SIZE] = new_item;
    printf("Added %d units of %s to the inventory.\n", quantity, name);
}

// Remove an item from the inventory
void remove_item(char *name, int quantity) {
    // Check if the item exists
    for (int i = 0; i < WAREHOUSE_SIZE; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Removed %d units of %s from the inventory.\n", quantity, name);
                return;
            } else {
                printf("Error: Not enough %s in stock.\n", name);
                return;
            }
        }
    }

    // Item not found
    printf("Error: Item not found.\n");
}

// Place an order
void place_order(char *name, int quantity) {
    // Check if the item exists
    for (int i = 0; i < WAREHOUSE_SIZE; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                float total_price = inventory[i].price * quantity;
                inventory[i].quantity -= quantity;
                printf("Order placed! Total price: $%.2f\n", total_price);
                return;
            } else {
                printf("Error: Not enough %s in stock.\n", name);
                return;
            }
        }
    }

    // Item not found
    printf("Error: Item not found.\n");
}

// Main function
int main() {
    // Welcome the user
    welcome();

    // Print the inventory
    print_inventory();

    // Add an item to the inventory
    add_item("Pears", 20, 0.75);

    // Remove an item from the inventory
    remove_item("Apples", 10);

    // Place an order
    place_order("Bananas", 15);

    return 0;
}