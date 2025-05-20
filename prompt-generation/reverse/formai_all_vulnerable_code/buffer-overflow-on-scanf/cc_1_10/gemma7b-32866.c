//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct Item {
    char name[50];
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

// Define a function to display all items in the warehouse
void displayItems(Item *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Item name: %s\n", items[i].name);
        printf("Item quantity: %d\n", items[i].quantity);
        printf("Item price: %.2f\n", items[i].price);
        printf("\n");
    }
}

// Define a function to search for an item in the warehouse
void searchItem(Item *items, int numItems) {
    char searchName[50];

    printf("Enter item name: ");
    scanf("%s", searchName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item name: %s\n", items[i].name);
            printf("Item quantity: %d\n", items[i].quantity);
            printf("Item price: %.2f\n", items[i].price);
            printf("\n");
        }
    }
}

// Define a function to update item quantity in the warehouse
void updateItemQuantity(Item *items, int numItems) {
    char updateName[50];
    int updateQuantity;

    printf("Enter item name: ");
    scanf("%s", updateName);

    printf("Enter new item quantity: ");
    scanf("%d", &updateQuantity);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, updateName) == 0) {
            items[i].quantity = updateQuantity;
            printf("Item name: %s\n", items[i].name);
            printf("Item quantity: %d\n", items[i].quantity);
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Create an array of items in the warehouse
    Item items[] = {
        {"Item 1", 10, 20.0},
        {"Item 2", 20, 30.0},
        {"Item 3", 30, 40.0}
    };

    // Number of items in the warehouse
    int numItems = 3;

    // Display all items in the warehouse
    displayItems(items, numItems);

    // Search for an item in the warehouse
    searchItem(items, numItems);

    // Update item quantity in the warehouse
    updateItemQuantity(items, numItems);

    return 0;
}