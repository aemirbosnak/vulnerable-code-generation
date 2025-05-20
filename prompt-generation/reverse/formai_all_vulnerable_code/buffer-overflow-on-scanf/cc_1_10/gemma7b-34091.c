//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

// Define the warehouse management system
void warehouse_management_system() {
    // Create an array of items
    Item items[MAX_ITEMS];

    // Initialize the items
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0;
    }

    // Display the items
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s: %d, $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }

    // Add an item
    printf("Enter the name of the item: ");
    scanf("%s", items[MAX_ITEMS - 1].name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &items[MAX_ITEMS - 1].quantity);

    printf("Enter the price of the item: ");
    scanf("%lf", &items[MAX_ITEMS - 1].price);

    // Update the items
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s: %d, $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    warehouse_management_system();

    return 0;
}