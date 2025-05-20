//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items in the warehouse
#define MAX_ITEM_NAME_LENGTH 50 // Maximum length of an item name


// Struct for each item in the warehouse
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
} Item;

// Struct for the warehouse itself
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, char *name, int quantity) {
    // Check if an item already exists with this name
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity += quantity;
            return;
        }
    }

    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Warehouse is full - cannot add item.\n");
        return;
    }

    // Add the new item
    strcpy(warehouse->items[warehouse->num_items].name, name);
    warehouse->items[warehouse->num_items].quantity = quantity;
    warehouse->num_items++;
}

// Function to remove an item from the warehouse
void remove_item(Warehouse *warehouse, char *name, int quantity) {
    // Find the item in the warehouse
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity < quantity) {
                printf("Insufficient quantity of %s in the warehouse.\n", name);
                return;
            }

            warehouse->items[i].quantity -= quantity;

            // If the quantity reaches zero, remove the item from the warehouse
            if (warehouse->items[i].quantity == 0) {
                memmove(&warehouse->items[i], &warehouse->items[i+1], sizeof(Item) * (warehouse->num_items - i - 1));
                warehouse->num_items--;
            }

            return;
        }
    }

    printf("%s not found in the warehouse.\n", name);
}

// Function to print the contents of the warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse contents:\n");

    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    int choice;
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    Warehouse warehouse = { .num_items = 0 };

    do {
        // Print the menu
        printf("\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Print warehouse contents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item to add: ");
                scanf("%s", name);
                printf("Enter the quantity to add: ");
                scanf("%d", &quantity);
                add_item(&warehouse, name, quantity);
                break;

            case 2:
                printf("Enter the name of the item to remove: ");
                scanf("%s", name);
                printf("Enter the quantity to remove: ");
                scanf("%d", &quantity);
                remove_item(&warehouse, name, quantity);
                break;

            case 3:
                print_warehouse(&warehouse);
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice - try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}