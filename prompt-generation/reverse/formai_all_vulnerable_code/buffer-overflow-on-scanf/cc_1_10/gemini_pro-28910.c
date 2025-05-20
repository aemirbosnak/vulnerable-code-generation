//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char *name;
    double price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Juice", 2.00},
    {"Water", 1.00},
    {"Muffin", 2.25},
    {"Donut", 1.75},
    {"Croissant", 3.00},
    {"Scone", 2.50},
    {"Cookie", 1.50}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
    struct MenuItem *item;
    int quantity;
};

// Define the structure of a bill
struct Bill {
    struct Order orders[MAX_ITEMS];
    int numItems;
    double total;
};

// Function to create a new order
struct Order *createOrder(struct MenuItem *item, int quantity) {
    struct Order *order = malloc(sizeof(struct Order));
    order->item = item;
    order->quantity = quantity;
    return order;
}

// Function to add an order to a bill
void addOrderToBill(struct Bill *bill, struct Order *order) {
    bill->orders[bill->numItems++] = *order;
    bill->total += order->item->price * order->quantity;
}

// Function to print a bill
void printBill(struct Bill *bill) {
    printf("Cafe Billing System\n");
    printf("===================\n");

    for (int i = 0; i < bill->numItems; i++) {
        printf("%s x%d: $%.2f\n", bill->orders[i].item->name, bill->orders[i].quantity, bill->orders[i].item->price * bill->orders[i].quantity);
    }

    printf("Total: $%.2f\n", bill->total);
}

// Main function
int main() {
    // Create a new bill
    struct Bill bill;
    bill.numItems = 0;
    bill.total = 0.0;

    // Get the customer's order
    int numItems;
    printf("How many items would you like to order? ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        char itemName[20];
        int quantity;

        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", itemName);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &quantity);

        // Find the menu item by name
        struct MenuItem *item;
        for (int j = 0; j < sizeof(menuItems) / sizeof(struct MenuItem); j++) {
            if (strcmp(menuItems[j].name, itemName) == 0) {
                item = &menuItems[j];
                break;
            }
        }

        // Create an order for the item
        struct Order *order = createOrder(item, quantity);

        // Add the order to the bill
        addOrderToBill(&bill, order);
    }

    // Print the bill
    printBill(&bill);

    return 0;
}