//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Pastry", 3.00}
};

// Define the order struct
struct OrderItem {
    struct MenuItem item;
    int quantity;
};

// Define the order struct
struct Order {
    struct OrderItem items[10];
    int numItems;
    float total;
};

// Function to add an item to the order
void addOrderItem(struct Order *order, struct MenuItem item, int quantity) {
    order->items[order->numItems].item = item;
    order->items[order->numItems].quantity = quantity;
    order->numItems++;
}

// Function to calculate the total of the order
float calculateTotal(struct Order *order) {
    float total = 0;
    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].item.price * order->items[i].quantity;
    }
    return total;
}

// Function to print the order
void printOrder(struct Order *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%d %s %f\n", order->items[i].quantity, order->items[i].item.name, order->items[i].item.price * order->items[i].quantity);
    }
    printf("Total: %f\n", order->total);
}

// Main function
int main() {
    // Create a new order
    struct Order order;
    order.numItems = 0;
    order.total = 0;

    // Add items to the order
    addOrderItem(&order, menuItems[0], 2);
    addOrderItem(&order, menuItems[1], 1);
    addOrderItem(&order, menuItems[4], 1);

    // Calculate the total of the order
    order.total = calculateTotal(&order);

    // Print the order
    printOrder(&order);

    return 0;
}