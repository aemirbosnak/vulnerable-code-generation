//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total cost of items ordered
float calculateTotalCost(int numItems, float *itemPrices, int *itemQuantities) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += itemPrices[i] * itemQuantities[i];
    }
    return totalCost;
}

// Function to print the order summary
void printOrderSummary(int numItems, char *itemNames[], float *itemPrices, int *itemQuantities) {
    printf("Order Summary:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d units - $%.2f\n", itemNames[i], itemQuantities[i], itemPrices[i]);
    }
    printf("Total Cost: $%.2f\n", calculateTotalCost(numItems, itemPrices, itemQuantities));
}

// Function to get user input for number of items to order
int getNumItems() {
    int numItems;
    do {
        printf("How many items would you like to order? ");
        scanf("%d", &numItems);
    } while (numItems <= 0);
    return numItems;
}

// Function to get user input for item names, prices, and quantities
void getItemDetails(int numItems, char *itemNames[], float *itemPrices, int *itemQuantities) {
    for (int i = 0; i < numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", itemNames[i]);
        printf("Enter item price: $");
        scanf("%f", &itemPrices[i]);
        printf("Enter item quantity: ");
        scanf("%d", &itemQuantities[i]);
    }
}

// Function to recursively call itself to handle multiple orders
void handleOrders() {
    int numItems;
    char itemNames[100][50];
    float itemPrices[100];
    int itemQuantities[100];

    // Get number of items from user
    numItems = getNumItems();

    // Get item details from user
    getItemDetails(numItems, itemNames, itemPrices, itemQuantities);

    // Print order summary
    printOrderSummary(numItems, itemNames, itemPrices, itemQuantities);

    // Ask user if they want to place another order
    char choice;
    do {
        printf("Would you like to place another order? (y/n) ");
        scanf(" %c", &choice);
    } while (choice!= 'y' && choice!= 'n');

    // If user wants to place another order, recursively call handleOrders()
    if (choice == 'y') {
        handleOrders();
    }
}

int main() {
    handleOrders();
    return 0;
}