//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: genius
#include <stdlib.h>
#include <stdio.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

// Define the cafe menu
struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Muffin", 2.00},
    {"Sandwich", 4.50}
};

// Get the number of menu items
int numMenuItems = sizeof(menu) / sizeof(struct MenuItem);

// Get the customer's order
void getOrder(int *order, int numItems) {
    printf("What would you like to order?\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("Enter the numbers of the items you want, separated by spaces: ");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &order[i]);
    }
}

// Calculate the total bill
float calculateBill(int *order, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += menu[order[i] - 1].price;
    }
    return total;
}

// Print the receipt
void printReceipt(int *order, int numItems, float total) {
    printf("\nYour order:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", menu[order[i] - 1].name, menu[order[i] - 1].price);
    }
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Get the customer's order
    int order[numMenuItems];
    getOrder(order, numMenuItems);

    // Calculate the total bill
    float total = calculateBill(order, numMenuItems);

    // Print the receipt
    printReceipt(order, numMenuItems, total);

    return 0;
}