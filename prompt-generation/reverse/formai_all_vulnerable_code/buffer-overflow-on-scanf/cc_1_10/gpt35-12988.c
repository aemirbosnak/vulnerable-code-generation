//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME 50

// Structure to represent an item in the warehouse
struct item {
    char name[MAX_ITEM_NAME];
    int quantity;
};

// Function to add an item to the warehouse
void add_item(struct item *inventory, int *num_items) {
    char item_name[MAX_ITEM_NAME];
    int quantity;
    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    // Check if item already exists
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            inventory[i].quantity += quantity;
            printf("Increased quantity of existing item\n");
            return;
        }
    }
    // Add new item to inventory
    if (*num_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    strcpy(inventory[*num_items].name, item_name);
    inventory[*num_items].quantity = quantity;
    (*num_items)++;
    printf("Added new item to warehouse\n");
}

// Function to remove an item from the warehouse
void remove_item(struct item *inventory, int *num_items) {
    char item_name[MAX_ITEM_NAME];
    printf("Enter item name to remove: ");
    scanf("%s", item_name);
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            // Remove item by shifting all subsequent items to the left
            for (int j = i; j < *num_items - 1; j++) {
                strcpy(inventory[j].name, inventory[j + 1].name);
                inventory[j].quantity = inventory[j + 1].quantity;
            }
            (*num_items)--;
            printf("Removed item from warehouse\n");
            return;
        }
    }
    printf("Item not found in warehouse\n");
}

// Function to print the warehouse inventory
void print_inventory(struct item *inventory, int num_items) {
    printf("Warehouse inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    struct item inventory[MAX_ITEMS];
    int num_items = 0;
    int choice;
    do {
        printf("Warehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Print inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                remove_item(inventory, &num_items);
                break;
            case 3:
                print_inventory(inventory, num_items);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}