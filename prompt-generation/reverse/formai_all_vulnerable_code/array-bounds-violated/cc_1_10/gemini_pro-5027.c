//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
typedef struct MenuItem {
    char *name;
    float price;
} MenuItem;

// Menu items
MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Cake", 3.00},
    {"Muffin", 2.00},
    {"Cookie", 1.00}
};

// Function to get the number of menu items
int getMenuItemCount() {
    return sizeof(menuItems) / sizeof(MenuItem);
}

// Function to get the menu item at the given index
MenuItem getMenuItem(int index) {
    return menuItems[index];
}

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < getMenuItemCount(); i++) {
        printf("%d. %s: $%.2f\n", i + 1, getMenuItem(i).name, getMenuItem(i).price);
    }
}

// Function to get the user's order
int getOrder() {
    int order;
    printf("Enter the number of the item you would like to order: ");
    scanf("%d", &order);
    return order;
}

// Function to calculate the total cost of the order
float calculateTotalCost(int order) {
    return getMenuItem(order - 1).price;
}

// Function to print the receipt
void printReceipt(int order, float totalCost) {
    printf("Receipt:\n");
    printf("Item: %s\n", getMenuItem(order - 1).name);
    printf("Price: $%.2f\n", getMenuItem(order - 1).price);
    printf("Total Cost: $%.2f\n", totalCost);
}

// Main function
int main() {
    // Print the menu
    printMenu();

    // Get the user's order
    int order = getOrder();

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(order);

    // Print the receipt
    printReceipt(order, totalCost);

    return 0;
}