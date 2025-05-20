//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
// Warehouse Management System in a post-apocalyptic style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for inventory and warehouse
typedef struct {
    char name[30];
    int quantity;
    double price;
} InventoryItem;

typedef struct {
    int id;
    char name[30];
    char location[30];
    InventoryItem* items;
    int num_items;
} Warehouse;

// Function to print warehouse information
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse %d: %s\n", warehouse->id, warehouse->name);
    printf("Location: %s\n", warehouse->location);
    printf("Items: \n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("  %s: %d x %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("\n");
}

// Function to add an item to a warehouse
void add_item(Warehouse* warehouse, InventoryItem item) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
}

// Function to remove an item from a warehouse
void remove_item(Warehouse* warehouse, char* item_name) {
    int index = -1;
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        warehouse->num_items--;
        for (int i = index; i < warehouse->num_items; i++) {
            warehouse->items[i] = warehouse->items[i+1];
        }
    }
}

// Function to find an item in a warehouse
InventoryItem* find_item(Warehouse* warehouse, char* item_name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, item_name) == 0) {
            return &warehouse->items[i];
        }
    }
    return NULL;
}

// Function to calculate the total cost of a warehouse
double total_cost(Warehouse* warehouse) {
    double total = 0;
    for (int i = 0; i < warehouse->num_items; i++) {
        total += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    return total;
}

int main() {
    // Create warehouses
    Warehouse warehouse1 = {1, "Warehouse 1", "123 Main St", NULL, 0};
    Warehouse warehouse2 = {2, "Warehouse 2", "456 Elm St", NULL, 0};

    // Add items to warehouses
    InventoryItem item1 = {"Apples", 100, 0.5};
    add_item(&warehouse1, item1);
    InventoryItem item2 = {"Bananas", 200, 0.3};
    add_item(&warehouse1, item2);
    InventoryItem item3 = {"Oranges", 300, 0.4};
    add_item(&warehouse2, item3);

    // Print warehouse information
    print_warehouse(&warehouse1);
    print_warehouse(&warehouse2);

    // Remove an item from a warehouse
    remove_item(&warehouse1, "Apples");
    print_warehouse(&warehouse1);

    // Find an item in a warehouse
    InventoryItem* item = find_item(&warehouse2, "Oranges");
    printf("Item found: %s x %d x %f\n", item->name, item->quantity, item->price);

    // Calculate the total cost of a warehouse
    printf("Total cost of Warehouse 2: %f\n", total_cost(&warehouse2));

    return 0;
}