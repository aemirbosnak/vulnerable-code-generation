//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure of an item in the warehouse
struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Define structure of a warehouse
struct Warehouse {
    int num_items;
    struct Item items[100]; // Warehouse can hold up to 100 items
};

// Function to add an item to the warehouse
void add_item(struct Warehouse* warehouse, int id, char name[], float price, int quantity) {
    // Check if warehouse is full
    if (warehouse->num_items >= 100) {
        printf("Warehouse is full. Cannot add item.\n");
        return;
    }
    // Create new item
    struct Item new_item = {id, name, price, quantity};
    // Add new item to warehouse
    warehouse->items[warehouse->num_items] = new_item;
    warehouse->num_items++;
    printf("Item added successfully.\n");
}

// Function to remove an item from the warehouse
void remove_item(struct Warehouse* warehouse, int id) {
    // Find item in warehouse
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i].id == id) {
            index = i;
            break;
        }
    }
    // Check if item was found
    if (index == -1) {
        printf("Item with ID %d not found in warehouse.\n", id);
        return;
    }
    // Remove item from warehouse
    for (int i = index; i < warehouse->num_items-1; i++) {
        warehouse->items[i] = warehouse->items[i+1];
    }
    warehouse->num_items--;
    printf("Item with ID %d removed successfully.\n", id);
}

// Function to display all items in the warehouse
void display_items(struct Warehouse* warehouse) {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        struct Item current_item = warehouse->items[i];
        printf("%d\t%s\t%.2f\t%d\n", current_item.id, current_item.name, current_item.price, current_item.quantity);
    }
}

int main() {
    struct Warehouse my_warehouse = {0}; // Initialize warehouse with no items
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display all items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                int id;
                scanf("%d", &id);
                printf("Enter item name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter item price: ");
                float price;
                scanf("%f", &price);
                printf("Enter item quantity: ");
                int quantity;
                scanf("%d", &quantity);
                add_item(&my_warehouse, id, name, price, quantity);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                int remove_id;
                scanf("%d", &remove_id);
                remove_item(&my_warehouse, remove_id);
                break;
            case 3:
                display_items(&my_warehouse);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}