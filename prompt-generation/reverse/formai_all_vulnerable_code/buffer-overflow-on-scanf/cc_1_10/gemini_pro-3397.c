//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
struct MenuItem {
    char name[50];
    float price;
};

// Define the order structure
struct Order {
    struct MenuItem item;
    int quantity;
};

// Create an array of menu items
struct MenuItem menu[] = {
    {"Coffee", 1.50},
    {"Tea", 1.25},
    {"Soda", 1.00},
    {"Pastry", 2.00},
    {"Muffin", 1.75},
};

// Get the number of menu items
int numMenuItems = sizeof(menu) / sizeof(struct MenuItem);

// Get the user's order
struct Order getOrder() {
    struct Order order;

    // Get the item name
    printf("Enter the item name: ");
    scanf("%s", order.item.name);

    // Find the item in the menu
    int found = 0;
    for (int i = 0; i < numMenuItems; i++) {
        if (strcmp(order.item.name, menu[i].name) == 0) {
            order.item = menu[i];
            found = 1;
            break;
        }
    }

    // If the item was not found, print an error message
    if (!found) {
        printf("Invalid item name.\n");
        return order;
    }

    // Get the quantity
    printf("Enter the quantity: ");
    scanf("%d", &order.quantity);

    return order;
}

// Calculate the total bill
float calculateBill(struct Order *orders, int numOrders) {
    float total = 0.0;

    for (int i = 0; i < numOrders; i++) {
        total += orders[i].item.price * orders[i].quantity;
    }

    return total;
}

// Print the receipt
void printReceipt(struct Order *orders, int numOrders, float total) {
    printf("\n\nReceipt:\n");

    for (int i = 0; i < numOrders; i++) {
        printf("%s x %d = $%.2f\n", orders[i].item.name, orders[i].quantity, orders[i].item.price * orders[i].quantity);
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    // Get the number of orders
    int numOrders;
    printf("Enter the number of orders: ");
    scanf("%d", &numOrders);

    // Create an array of orders
    struct Order *orders = malloc(sizeof(struct Order) * numOrders);

    // Get each order from the user
    for (int i = 0; i < numOrders; i++) {
        orders[i] = getOrder();
    }

    // Calculate the total bill
    float total = calculateBill(orders, numOrders);

    // Print the receipt
    printReceipt(orders, numOrders, total);

    // Free the allocated memory
    free(orders);

    return 0;
}