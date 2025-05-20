//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define struct for item in warehouse
typedef struct item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define struct for warehouse
typedef struct warehouse {
    Item items[MAX_SIZE];
    int count;
} Warehouse;

// Function to add an item to the warehouse
void add_item(Warehouse *warehouse, char *name, int quantity, float price) {
    Item item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    warehouse->items[warehouse->count] = item;
    warehouse->count++;
}

// Function to print the contents of the warehouse
void print_warehouse(Warehouse warehouse) {
    printf("Current warehouse inventory:\n");
    printf("%-20s %-10s %-10s\n", "NAME", "QUANTITY", "PRICE");
    for (int i = 0; i < warehouse.count; i++) {
        Item item = warehouse.items[i];
        printf("%-20s %-10d %-10.2f\n", item.name, item.quantity, item.price);
    }
}

int main() {
    // Initialize warehouse
    Warehouse warehouse;
    warehouse.count = 0;

    // Add items to the warehouse
    add_item(&warehouse, "Shampoo", 50, 3.00);
    add_item(&warehouse, "Toothpaste", 100, 1.50);
    add_item(&warehouse, "Soap", 75, 2.25);

    // Print the initial warehouse inventory
    print_warehouse(warehouse);

    // Update item quantity
    for (int i = 0; i < warehouse.count; i++) {
        Item *item = &(warehouse.items[i]);
        if (strcmp(item->name, "Toothpaste") == 0) {
            item->quantity -= 25;
        }
    }

    // Print the updated warehouse inventory
    print_warehouse(warehouse);

    return 0;
}