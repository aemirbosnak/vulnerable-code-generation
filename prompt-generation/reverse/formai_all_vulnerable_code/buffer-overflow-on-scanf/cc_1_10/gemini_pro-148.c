//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    double price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Water", 1.00},
    {"Muffin", 3.00},
    {"Croissant", 3.50},
    {"Bagel", 2.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the data structure for the order
struct Order {
    struct MenuItem *items[MAX_ITEMS];
    int numItems;
    double total;
};

// Function to create a new order
struct Order *createOrder() {
    struct Order *order = malloc(sizeof(struct Order));
    order->numItems = 0;
    order->total = 0.0;
    return order;
}

// Function to add an item to an order
void addItemToOrder(struct Order *order, struct MenuItem *item) {
    if (order->numItems < MAX_ITEMS) {
        order->items[order->numItems] = item;
        order->numItems++;
        order->total += item->price;
    }
}

// Function to print the order
void printOrder(struct Order *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s: $%.2f\n", order->items[i]->name, order->items[i]->price);
    }
    printf("Total: $%.2f\n", order->total);
}

// Function to get the user's input
int getInput() {
    int input;
    printf("Enter the number of the item you would like to order (0 to exit): ");
    scanf("%d", &input);
    return input;
}

// Main function
int main() {
    // Create a new order
    struct Order *order = createOrder();

    // Loop until the user enters 0
    int input;
    do {
        // Get the user's input
        input = getInput();

        // If the user entered a valid item number, add it to the order
        if (input > 0 && input <= sizeof(menuItems) / sizeof(struct MenuItem)) {
            addItemToOrder(order, &menuItems[input - 1]);
        }
    } while (input != 0);

    // Print the order
    printOrder(order);

    // Free the memory allocated for the order
    free(order);

    return 0;
}