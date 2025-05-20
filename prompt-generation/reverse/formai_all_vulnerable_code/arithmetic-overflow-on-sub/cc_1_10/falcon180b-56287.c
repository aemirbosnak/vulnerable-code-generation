//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

// Structure for a single item
typedef struct {
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Item;

// Function to add an item to the list
void addItem(Item* items, int* numItems) {
    Item newItem;

    // Get input from user
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the price per unit: $");
    scanf("%lf", &newItem.price);
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);

    // Add the new item to the list
    *numItems += 1;
    items[*numItems - 1] = newItem;
}

// Function to print the list of items
void printItems(Item* items, int numItems) {
    printf("Name\tPrice\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t$%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Function to calculate the total cost of the items
double calculateTotalCost(Item* items, int numItems) {
    double totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    // Get input from user
    printf("Enter the number of items you want to add: ");
    scanf("%d", &numItems);

    // Add items to the list
    for (int i = 0; i < numItems; i++) {
        addItem(items, &numItems);
    }

    // Print the list of items
    printf("\nList of items:\n");
    printItems(items, numItems);

    // Calculate the total cost of the items
    double totalCost = calculateTotalCost(items, numItems);
    printf("\nTotal cost: $%.2f\n", totalCost);

    return 0;
}