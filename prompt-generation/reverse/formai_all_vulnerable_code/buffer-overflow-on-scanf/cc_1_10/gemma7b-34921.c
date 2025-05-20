//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a menu item
typedef struct MenuItem {
    char name[20];
    float price;
    int quantity;
} MenuItem;

// Define a function to calculate the total cost of an order
float calculateTotalCost(MenuItem items[], int numItems) {
    float totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu(MenuItem items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s - %.2f (Qty: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Define a function to take an order
void takeOrder(MenuItem items[], int numItems) {
    char itemName[20];
    int itemQuantity;

    printf("Enter item name:");
    scanf("%s", itemName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            printf("Enter item quantity:");
            scanf("%d", &itemQuantity);

            items[i].quantity += itemQuantity;
            break;
        }
    }

    if (itemQuantity == 0) {
        printf("Item not found.\n");
    }
}

int main() {
    // Create an array of menu items
    MenuItem items[] = {
        {"Coffee", 2.50, 0},
        {"Tea", 3.00, 0},
        {"Juice", 2.00, 0},
        {"Soda", 2.25, 0}
    };

    int numItems = sizeof(items) / sizeof(MenuItem);

    // Print the menu
    printMenu(items, numItems);

    // Take an order
    takeOrder(items, numItems);

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(items, numItems);

    // Print the total cost of the order
    printf("Total cost: %.2f\n", totalCost);

    return 0;
}