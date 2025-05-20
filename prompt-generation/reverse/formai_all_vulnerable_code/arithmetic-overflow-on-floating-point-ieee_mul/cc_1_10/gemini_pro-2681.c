//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a menu item
struct MenuItem {
    char name[50];
    float price;
};

// Define an array of menu items
struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Juice", 2.00},
    {"Water", 1.00},
};

// Define a struct to represent an order item
struct OrderItem {
    struct MenuItem *item;
    int quantity;
};

// Define a struct to represent an order
struct Order {
    struct OrderItem *items;
    int numItems;
    float total;
};

// Function to create a new order
struct Order *createOrder() {
    struct Order *order = malloc(sizeof(struct Order));
    order->items = NULL;
    order->numItems = 0;
    order->total = 0.0;
    return order;
}

// Function to add an item to an order
void addItemToOrder(struct Order *order, struct MenuItem *item, int quantity) {
    // Allocate memory for the new order item
    struct OrderItem *orderItem = malloc(sizeof(struct OrderItem));

    // Set the order item's item and quantity
    orderItem->item = item;
    orderItem->quantity = quantity;

    // Add the order item to the order's list of items
    order->items = realloc(order->items, (order->numItems + 1) * sizeof(struct OrderItem));
    order->items[order->numItems] = *orderItem;

    // Increment the order's number of items
    order->numItems++;

    // Update the order's total
    order->total += item->price * quantity;
}

// Function to print an order
void printOrder(struct Order *order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s x %d = $%.2f\n", order->items[i].item->name, order->items[i].quantity, order->items[i].item->price * order->items[i].quantity);
    }
    printf("Total: $%.2f\n", order->total);
}

// Main function
int main() {
    // Create a new order
    struct Order *order = createOrder();

    // Add some items to the order
    addItemToOrder(order, &menu[0], 2);
    addItemToOrder(order, &menu[1], 1);
    addItemToOrder(order, &menu[2], 3);

    // Print the order
    printOrder(order);

    // Free the memory allocated for the order
    free(order);

    return 0;
}