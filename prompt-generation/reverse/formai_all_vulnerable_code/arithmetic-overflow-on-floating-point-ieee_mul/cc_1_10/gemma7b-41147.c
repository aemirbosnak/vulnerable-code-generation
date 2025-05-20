//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item {
    char name[50];
    int quantity;
    double price;
} Item;

// Define a function to calculate the total cost of an item
double calculateTotalCost(Item item) {
    return item.quantity * item.price;
}

// Define a function to calculate the total cost of all items
double calculateTotalCostForItems(Item items[], int numItems) {
    double totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += calculateTotalCost(items[i]);
    }
    return totalCost;
}

// Define a function to print the billing details
void printBillingDetails(Item items[], int numItems) {
    printf("---------------------------------------------------\n");
    printf("Bill\n");
    printf("---------------------------------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d @ $%.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("Total Cost: $%.2lf\n", calculateTotalCostForItems(items, numItems));
    printf("---------------------------------------------------\n");
}

int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 2, 3.50},
        {"Tea", 1, 2.00},
        {"Juice", 3, 4.00}
    };

    // Calculate the total cost of all items
    double totalCost = calculateTotalCostForItems(items, 3);

    // Print the billing details
    printBillingDetails(items, 3);

    // Print the total cost
    printf("Total Cost: $%.2lf\n", totalCost);

    return 0;
}