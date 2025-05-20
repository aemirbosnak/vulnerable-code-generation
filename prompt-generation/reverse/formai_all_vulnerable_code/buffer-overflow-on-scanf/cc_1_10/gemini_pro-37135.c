//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: random
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
    {"Pastry", 3.00},
    {"Sandwich", 5.00},
    {"Salad", 4.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the order structure
struct Order {
    struct MenuItem item;
    int quantity;
};

// Define the bill structure
struct Bill {
    struct Order orders[MAX_ITEMS];
    int numItems;
    float total;
};

// Get the user's order
void getOrder(struct Order *order) {
    printf("Enter the name of the item you want to order: ");
    scanf("%s", order->item.name);

    printf("Enter the quantity of the item you want to order: ");
    scanf("%d", &order->quantity);
}

// Add an item to the bill
void addOrder(struct Bill *bill, struct Order order) {
    // Find the item in the menu
    int i;
    for (i = 0; i < sizeof(menuItems) / sizeof(menuItems[0]); i++) {
        if (strcmp(order.item.name, menuItems[i].name) == 0) {
            break;
        }
    }

    // If the item was not found, print an error message and return
    if (i == sizeof(menuItems) / sizeof(menuItems[0])) {
        printf("Error: Item not found.\n");
        return;
    }

    // Add the item to the bill
    bill->orders[bill->numItems] = order;
    bill->total += order.quantity * menuItems[i].price;
    bill->numItems++;
}

// Print the bill
void printBill(struct Bill *bill) {
    printf("Order Summary\n");
    printf("-------------------------------\n");
    for (int i = 0; i < bill->numItems; i++) {
        printf("%s x %d = $%.2f\n", bill->orders[i].item.name, bill->orders[i].quantity, bill->orders[i].item.price * bill->orders[i].quantity);
    }
    printf("Total: $%.2f\n", bill->total);
}

// Main function
int main() {
    // Create a new bill
    struct Bill bill;
    bill.numItems = 0;
    bill.total = 0.0;

    // Get the user's order
    int numOrders;
    printf("How many items would you like to order? ");
    scanf("%d", &numOrders);

    for (int i = 0; i < numOrders; i++) {
        struct Order order;
        getOrder(&order);
        addOrder(&bill, order);
    }

    // Print the bill
    printBill(&bill);

    return 0;
}