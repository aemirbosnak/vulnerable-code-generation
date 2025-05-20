//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

struct warehouse {
    struct item items[100];
    int num_items;
};

int main() {
    // Create a warehouse
    struct warehouse warehouse;
    warehouse.num_items = 0;

    // Add some items to the warehouse
    strcpy(warehouse.items[0].name, "Apple");
    warehouse.items[0].quantity = 10;
    warehouse.items[0].price = 1.0;

    strcpy(warehouse.items[1].name, "Orange");
    warehouse.items[1].quantity = 20;
    warehouse.items[1].price = 2.0;

    strcpy(warehouse.items[2].name, "Banana");
    warehouse.items[2].quantity = 30;
    warehouse.items[2].price = 3.0;

    // Print the warehouse inventory
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse.num_items; i++) {
        printf("%s: %d, $%.2f\n", warehouse.items[i].name, warehouse.items[i].quantity, warehouse.items[i].price);
    }

    // Find an item in the warehouse
    char item_name[50];
    printf("Enter the name of the item you want to find: ");
    scanf("%s", item_name);

    int item_index = -1;
    for (int i = 0; i < warehouse.num_items; i++) {
        if (strcmp(warehouse.items[i].name, item_name) == 0) {
            item_index = i;
            break;
        }
    }

    // Print the item's information
    if (item_index >= 0) {
        printf("Item found:\n");
        printf("%s: %d, $%.2f\n", warehouse.items[item_index].name, warehouse.items[item_index].quantity, warehouse.items[item_index].price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}