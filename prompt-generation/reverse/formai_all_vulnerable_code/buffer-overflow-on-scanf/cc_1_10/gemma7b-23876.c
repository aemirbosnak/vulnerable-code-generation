//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a coffee item
typedef struct CoffeeItem {
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Define a function to calculate the total cost of a coffee order
float calculateTotalCost(CoffeeItem *items, int numItems) {
    float totalCost = 0.0f;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu(CoffeeItem *items, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("%s - %f\n", items[i].name, items[i].price);
    }
}

// Define a function to take an order
void takeOrder(CoffeeItem *items, int numItems) {
    char itemName[20];
    int itemQuantity;

    printf("Enter the name of the coffee item:");
    scanf("%s", itemName);

    for (int i = 0; i < numItems; i++) {
        if (strcmp(itemName, items[i].name) == 0) {
            printf("Enter the quantity of the item:");
            scanf("%d", &itemQuantity);

            items[i].quantity += itemQuantity;
            break;
        }
    }

    if (itemQuantity == 0) {
        printf("Error: item not found.\n");
    }
}

int main() {
    // Create an array of coffee items
    CoffeeItem items[] = {
        {"Coffee", 2.0f, 0},
        {"Cappuccino", 3.0f, 0},
        {"Latte", 4.0f, 0}
    };

    // Print the menu
    printMenu(items, 3);

    // Take an order
    takeOrder(items, 3);

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(items, 3);

    // Print the total cost
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}