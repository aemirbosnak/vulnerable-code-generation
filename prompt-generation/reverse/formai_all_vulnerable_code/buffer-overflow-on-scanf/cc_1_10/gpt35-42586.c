//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 50

// Define struct for inventory items
typedef struct {
    char name[MAX_LENGTH];
    int quantity;
    float price;
} Item;

// Global variables for inventory and number of items
Item inventory[MAX_ITEMS];
int num_items = 0;

// Function to add an item to the inventory
void add_item() {
    char name[MAX_LENGTH];
    int quantity;
    float price;

    printf("Enter the name of the new item: ");
    scanf("%s", name);
    printf("Enter the quantity of the new item: ");
    scanf("%d", &quantity);
    printf("Enter the price of the new item: ");
    scanf("%f", &price);

    // Check if item already exists in inventory
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item already exists in inventory!\n");
            return;
        }
    }

    // Add new item to inventory
    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    inventory[num_items].price = price;
    num_items++;
}

// Function to remove an item from the inventory
void remove_item() {
    char name[MAX_LENGTH];

    printf("Enter the name of the item to remove: ");
    scanf("%s", name);

    int index = -1;
    // Find index of item to remove
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory!\n");
        return;
    }

    // Shift items after index to the left
    for (int i = index; i < num_items - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    // Decrease number of items
    num_items--;
    printf("Item removed from inventory!\n");
}

// Function to display the inventory
void display_inventory() {
    printf("Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s %-10d $%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    do {
        // Print menu options
        printf("\nWarehouse Management System\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}