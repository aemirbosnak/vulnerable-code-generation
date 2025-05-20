//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a menu item
typedef struct MenuItem {
    char name[20];
    int price;
    int quantity;
} MenuItem;

// Define a function to calculate the total cost of an order
int calculateTotalCost(MenuItem *menu, int numItems) {
    int totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += menu[i].price * menu[i].quantity;
    }
    return totalCost;
}

// Define a function to print the menu
void printMenu(MenuItem *menu, int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d (Q: %d)\n", menu[i].name, menu[i].price, menu[i].quantity);
    }
}

int main() {
    // Create an array of menu items
    MenuItem menu[] = {
        {"Coffee", 50, 0},
        {"Tea", 40, 1},
        {"Juice", 30, 2},
        {"Smoothie", 60, 0},
        {"Water", 20, 3}
    };

    // Print the menu
    printMenu(menu, 5);

    // Get the number of items in the order
    int numItems = 0;
    printf("Enter the number of items in your order: ");
    scanf("%d", &numItems);

    // Calculate the total cost of the order
    int totalCost = calculateTotalCost(menu, numItems);

    // Print the total cost of the order
    printf("Total cost: %d\n", totalCost);

    return 0;
}