//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store inventory items
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the inventory
void addItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);

    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter item price: ");
    scanf("%f", &item->price);
}

// Define a function to remove an item from the inventory
void removeItem(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);

    item->quantity--;
    printf("Item removed successfully.\n");
}

// Define a function to update item quantity
void updateQuantity(Item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);

    printf("Enter new item quantity: ");
    scanf("%d", &item->quantity);
}

// Define a function to display inventory items
void displayInventory(Item *item) {
    printf("Inventory Items:\n");
    for (int i = 0; i < item->quantity; i++) {
        printf("%s - %d - %.2f\n", item->name, item->quantity, item->price);
    }
}

int main() {
    Item item;

    // Add an item to the inventory
    addItem(&item);

    // Remove an item from the inventory
    removeItem(&item);

    // Update item quantity
    updateQuantity(&item);

    // Display inventory items
    displayInventory(&item);

    return 0;
}