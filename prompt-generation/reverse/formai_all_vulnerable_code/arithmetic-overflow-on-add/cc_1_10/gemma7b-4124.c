//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a menu item
typedef struct MenuItem {
    char name[50];
    int price;
    int quantity;
} MenuItem;

// Define a function to calculate the total cost of an order
int calculateTotalCost(MenuItem items[], int numItems) {
    int totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu(MenuItem items[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d, $%d\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to process an order
void processOrder(MenuItem items[], int numItems) {
    char itemName[50];
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
    // Define an array of menu items
    MenuItem items[] = {
        {"Coffee", 2, 5},
        {"Tea", 1, 3},
        {"Juice", 3, 2}
    };

    // Print the menu
    printMenu(items, 3);

    // Process an order
    processOrder(items, 3);

    // Calculate the total cost of the order
    int totalCost = calculateTotalCost(items, 3);

    // Print the total cost of the order
    printf("Total cost: $%d\n", totalCost);

    return 0;
}