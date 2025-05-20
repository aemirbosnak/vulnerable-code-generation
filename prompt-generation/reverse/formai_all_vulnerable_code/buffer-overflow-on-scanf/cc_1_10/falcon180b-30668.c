//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_ITEM_NAME_LENGTH 50

// Define structure for each item in the inventory
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    double price;
} Item;

// Function to add an item to the inventory
void addItem(Item inventory[], int numItems) {
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price per unit: ");
    scanf("%lf", &newItem.price);
    inventory[numItems] = newItem;
    numItems++;
}

// Function to display all items in the inventory
void displayInventory(Item inventory[], int numItems) {
    printf("Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s | %d | $%.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for an item in the inventory
int searchInventory(Item inventory[], int numItems, char *itemName) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of an item in the inventory
void updateQuantity(Item inventory[], int numItems, int itemIndex, int newQuantity) {
    inventory[itemIndex].quantity = newQuantity;
}

// Function to calculate the total value of all items in the inventory
double calculateTotalValue(Item inventory[], int numItems) {
    double totalValue = 0;
    for (int i = 0; i < numItems; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    return totalValue;
}

int main() {
    Item inventory[MAX_ITEMS];
    int numItems = 0;

    // Add some items to the inventory
    addItem(inventory, numItems);
    addItem(inventory, numItems);
    addItem(inventory, numItems);

    // Display the inventory
    displayInventory(inventory, numItems);

    // Search for an item
    int itemIndex = searchInventory(inventory, numItems, "Item 1");
    if (itemIndex!= -1) {
        printf("Found item %s at index %d\n", inventory[itemIndex].name, itemIndex);
    } else {
        printf("Item not found\n");
    }

    // Update the quantity of an item
    int newQuantity = 50;
    updateQuantity(inventory, numItems, 0, newQuantity);

    // Display the updated inventory
    displayInventory(inventory, numItems);

    // Calculate the total value of all items
    double totalValue = calculateTotalValue(inventory, numItems);
    printf("Total value of inventory: $%.2lf\n", totalValue);

    return 0;
}