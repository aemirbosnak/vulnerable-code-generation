//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the warehouse
void addItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter item price: ");
    scanf("%f", &item->price);
}

// Define a function to remove an item from the warehouse
void removeItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    item->quantity--;
    printf("Item removed: %s", item->name);
}

// Define a function to update item quantity
void updateQuantity(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    printf("Item quantity updated: %s", item->name);
}

// Define a function to display warehouse items
void displayItems(Item *item) {
    printf("List of warehouse items:\n");
    for (int i = 0; i < item->quantity; i++) {
        printf("%s, %d, %.2f\n", item->name, item->quantity, item->price);
    }
}

int main() {
    // Create an array of items
    Item items[100];

    // Add some items to the warehouse
    addItem(&items[0]);
    addItem(&items[1]);
    addItem(&items[2]);

    // Display the warehouse items
    displayItems(items);

    // Remove an item from the warehouse
    removeItem(&items[0]);

    // Update the quantity of an item
    updateQuantity(&items[1]);

    // Display the warehouse items after updates
    displayItems(items);

    return 0;
}