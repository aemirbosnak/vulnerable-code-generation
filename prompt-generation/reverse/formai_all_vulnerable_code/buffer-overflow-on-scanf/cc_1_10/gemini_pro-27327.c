//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Cookie", 0.50},
    {"Muffin", 1.00},
    {"Bagel", 2.00}
};

// Get the number of menu items
int numMenuItems = sizeof(menuItems) / sizeof(struct MenuItem);

// Get the user's order
void getOrder(int *order, int numItems) {
    int i, item;
    for (i = 0; i < numItems; i++) {
        printf("Enter the quantity of %s you want: ", menuItems[i].name);
        scanf("%d", &item);
        order[i] = item;
    }
}

// Calculate the total bill
float calculateBill(int *order, int numItems) {
    int i;
    float total = 0.0;
    for (i = 0; i < numItems; i++) {
        total += menuItems[i].price * order[i];
    }
    return total;
}

// Print the receipt
void printReceipt(int *order, int numItems, float total) {
    int i;
    printf("\n\nReceipt:\n");
    for (i = 0; i < numItems; i++) {
        if (order[i] > 0) {
            printf("%s: %d x $%.2f = $%.2f\n", menuItems[i].name, order[i], menuItems[i].price, order[i] * menuItems[i].price);
        }
    }
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    int order[numMenuItems];
    float total;

    // Get the user's order
    getOrder(order, numMenuItems);

    // Calculate the total bill
    total = calculateBill(order, numMenuItems);

    // Print the receipt
    printReceipt(order, numMenuItems, total);

    return 0;
}