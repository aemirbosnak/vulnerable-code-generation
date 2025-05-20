//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

// Create an array of menu items
struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Muffin", 2.00}
};

// Get the number of menu items
int numMenuItems = sizeof(menuItems) / sizeof(struct MenuItem);

// Get the customer's order
void getOrder(int *order, int numItems) {
    for (int i = 0; i < numItems; i++) {
        printf("Enter the quantity of %s: ", menuItems[i].name);
        scanf("%d", &order[i]);
    }
}

// Calculate the total bill
float calculateBill(int *order, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += menuItems[i].price * order[i];
    }
    return total;
}

// Print the receipt
void printReceipt(int *order, int numItems, float total) {
    printf("\nReceipt:\n");
    for (int i = 0; i < numItems; i++) {
        if (order[i] > 0) {
            printf("%d %s: $%.2f\n", order[i], menuItems[i].name, menuItems[i].price * order[i]);
        }
    }
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Get the number of items ordered
    int numItems;
    printf("How many items would you like to order? ");
    scanf("%d", &numItems);

    // Allocate memory for the order array
    int *order = malloc(sizeof(int) * numItems);

    // Get the customer's order
    getOrder(order, numItems);

    // Calculate the total bill
    float total = calculateBill(order, numItems);

    // Print the receipt
    printReceipt(order, numItems, total);

    // Free the memory allocated for the order array
    free(order);

    return 0;
}