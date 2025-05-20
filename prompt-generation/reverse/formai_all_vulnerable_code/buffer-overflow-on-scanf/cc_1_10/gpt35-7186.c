//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

// Item struct
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

// Warehouse struct
typedef struct Warehouse {
    Item items[MAX_ITEMS];
    int num_items;
    int max_capacity;
} Warehouse;

// Function prototypes
void addItem(Warehouse *warehouse, char *name, int quantity);
void removeItem(Warehouse *warehouse, char *name, int quantity);
void printInventory(Warehouse *warehouse);
void printMenu();
void clearInputBuffer();

int main() {
    // Initialize warehouse
    Warehouse warehouse = { .num_items = 0, .max_capacity = MAX_ITEMS };

    // Print welcome message
    printf("Welcome to the Medieval Warehouse Management System!\n");

    // Loop until user chooses to exit
    int choice = 0;
    while (choice != 4) {
        printMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        // Handle user choice
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int quantity;
                printf("Enter item name: ");
                scanf("%s", name);
                clearInputBuffer();
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                clearInputBuffer();
                addItem(&warehouse, name, quantity);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                int quantity;
                printf("Enter item name: ");
                scanf("%s", name);
                clearInputBuffer();
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                clearInputBuffer();
                removeItem(&warehouse, name, quantity);
                break;
            }
            case 3:
                printInventory(&warehouse);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

// Function to add an item to the warehouse
void addItem(Warehouse *warehouse, char *name, int quantity) {
    // Check if the item already exists
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(name, warehouse->items[i].name) == 0) {
            // Item already exists, add to the quantity
            warehouse->items[i].quantity += quantity;
            printf("%d %s has been added to the warehouse.\n", quantity, name);
            return;
        }
    }

    // Item does not exist, add a new item
    if (warehouse->num_items >= warehouse->max_capacity) {
        // Warehouse is full
        printf("The warehouse is full. Cannot add %s.\n", name);
        return;
    }

    Item item = { .quantity = quantity };
    strcpy(item.name, name);
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
    printf("%d %s has been added to the warehouse.\n", quantity, name);
}

// Function to remove an item from the warehouse
void removeItem(Warehouse *warehouse, char *name, int quantity) {
    // Check if the item exists
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(name, warehouse->items[i].name) == 0) {
            // Item exists
            if (quantity > warehouse->items[i].quantity) {
                // Not enough quantity to remove
                printf("There are not enough %s to remove from the warehouse.\n", name);
                return;
            } else {
                // Remove the quantity
                warehouse->items[i].quantity -= quantity;
                if (warehouse->items[i].quantity == 0) {
                    // Remove the entire item if no quantity remains
                    Item item = warehouse->items[warehouse->num_items - 1];
                    warehouse->items[i] = item;
                    warehouse->num_items--;
                }
                printf("%d %s has been removed from the warehouse.\n", quantity, name);
                return;
            }
        }
    }

    // Item does not exist
    printf("%s does not exist in the warehouse.\n", name);
}

// Function to print the current inventory of the warehouse
void printInventory(Warehouse *warehouse) {
    printf("Current inventory:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        Item item = warehouse->items[i];
        printf("%d %s\n", item.quantity, item.name);
    }
}

// Function to print the menu
void printMenu() {
    printf("\nChoose an option:\n"
           "1. Add item\n"
           "2. Remove item\n"
           "3. Print current inventory\n"
           "4. Exit\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}