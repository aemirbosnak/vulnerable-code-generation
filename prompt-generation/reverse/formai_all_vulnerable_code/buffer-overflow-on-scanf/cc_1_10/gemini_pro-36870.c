//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Water", 1.00},
    {"Muffin", 2.00},
    {"Scone", 2.25},
    {"Cookie", 1.50}
};

// Get the user's order
void getOrder(struct MenuItem *menu, int numItems, int *order) {
    int i;

    printf("Welcome to the cafe!\n");
    printf("Here is our menu:\n");

    // Print the menu
    for (i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }

    printf("Please enter the numbers of the items you would like to order (separated by spaces): ");

    // Get the user's order
    for (i = 0; i < numItems; i++) {
        scanf("%d", &order[i]);
    }
}

// Calculate the total cost of the order
float calculateTotal(struct MenuItem *menu, int *order, int numItems) {
    int i;
    float total = 0.0;

    // Calculate the total cost
    for (i = 0; i < numItems; i++) {
        total += menu[order[i] - 1].price;
    }

    return total;
}

// Print the receipt
void printReceipt(struct MenuItem *menu, int *order, int numItems, float total) {
    int i;

    printf("\nHere is your receipt:\n");

    // Print the ordered items
    for (i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", menu[order[i] - 1].name, menu[order[i] - 1].price);
    }

    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    int numItems = sizeof(menu) / sizeof(menu[0]);
    int order[numItems];
    float total;

    // Get the user's order
    getOrder(menu, numItems, order);

    // Calculate the total cost of the order
    total = calculateTotal(menu, order, numItems);

    // Print the receipt
    printReceipt(menu, order, numItems, total);

    return 0;
}