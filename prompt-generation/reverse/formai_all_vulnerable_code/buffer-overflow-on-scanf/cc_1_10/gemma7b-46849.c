//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the store
void addItem(Item **items, int *numItems) {
    // Allocate memory for a new item
    Item *newItem = malloc(sizeof(Item));

    // Get the item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", newItem->name);

    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem->price);

    // Add the new item to the store
    items[*numItems] = newItem;
    (*numItems)++;
}

// Define a function to remove an item from the store
void removeItem(Item **items, int *numItems) {
    // Get the item name from the user
    char itemName[50];
    printf("Enter item name: ");
    scanf("%s", itemName);

    // Search for the item to remove
    int found = 0;
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(items[i]->name, itemName) == 0) {
            found = 1;
            break;
        }
    }

    // If the item was found, remove it from the store
    if (found) {
        for (int i = i; i < *numItems - 1; i++) {
            items[i] = items[i + 1];
        }
        (*numItems)--;
    } else {
        printf("Item not found.\n");
    }
}

// Define a function to display the store items
void displayItems(Item **items, int numItems) {
    // Print the list of items
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d - %.2f\n", items[i]->name, items[i]->quantity, items[i]->price);
    }
}

int main() {
    // Create an array of items
    Item **items = NULL;

    // Initialize the number of items to 0
    int numItems = 0;

    // Add some items to the store
    addItem(items, &numItems);
    addItem(items, &numItems);
    addItem(items, &numItems);

    // Display the store items
    displayItems(items, numItems);

    // Remove some items from the store
    removeItem(items, &numItems);
    removeItem(items, &numItems);

    // Display the store items after removing items
    displayItems(items, numItems);

    return 0;
}