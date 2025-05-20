//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a menu item
typedef struct MenuItem {
    char name[50];
    float price;
    int quantity;
} MenuItem;

// Define a function to calculate the total cost of an order
float calculateTotalCost(MenuItem *menuItems, int numItems) {
    float totalCost = 0.0f;
    for (int i = 0; i < numItems; i++) {
        totalCost += menuItems[i].price * menuItems[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu(MenuItem *menuItems, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f, Quantity: %d\n", menuItems[i].name, menuItems[i].price, menuItems[i].quantity);
    }
}

int main() {
    // Create an array of menu items
    MenuItem menuItems[] = {
        {"Coffee", 2.50, 10},
        {"Tea", 3.00, 8},
        {"Juice", 2.00, 12},
        {"Smoothie", 3.50, 6}
    };

    // Print the menu
    printMenu(menuItems, 4);

    // Get the customer's order
    printf("Enter your order: ");
    char order[50];
    scanf("%s", order);

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(menuItems, 4);

    // Print the total cost of the order
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}