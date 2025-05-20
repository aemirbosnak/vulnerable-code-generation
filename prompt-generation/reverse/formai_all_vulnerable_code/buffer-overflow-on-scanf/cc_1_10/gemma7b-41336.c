//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a coffee item
typedef struct CoffeeItem {
    char name[20];
    double price;
    int quantity;
} CoffeeItem;

// Define the function to calculate the total cost of a coffee order
double calculateTotalCost(CoffeeItem *items, int numItems) {
    double totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define the function to print the menu
void printMenu(CoffeeItem *items, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    // Create an array of coffee items
    CoffeeItem items[] = {
        {"Cappuccino", 2.50, 5},
        {"Latte", 3.00, 3},
        {"Americano", 2.00, 2},
        {"Mocha", 3.50, 4}
    };

    // Print the menu
    printMenu(items, 4);

    // Get the user's order
    int numItems = 0;
    printf("Enter the number of items you want to order: ");
    scanf("%d", &numItems);

    // Calculate the total cost of the order
    double totalCost = calculateTotalCost(items, numItems);

    // Print the total cost of the order
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}