//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of menu items
#define MAX_MENU_ITEMS 100

// Define the structure for a menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure for an order
typedef struct {
    int numItems;
    MenuItem items[MAX_MENU_ITEMS];
} Order;

// Function to add a menu item to the order
void addItem(Order* order) {
    int i = 0;
    while (i < MAX_MENU_ITEMS && order->numItems < MAX_MENU_ITEMS) {
        printf("Enter the name of the item: ");
        scanf("%s", order->items[i].name);
        printf("Enter the price of the item: $");
        scanf("%lf", &order->items[i].price);
        printf("\n");
        i++;
        order->numItems++;
    }
}

// Function to calculate the total price of an order
double calculateTotal(Order order) {
    double total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the details of an order
void printOrder(Order order) {
    printf("Order Details:\n");
    printf("--------------------\n");
    printf("Number of Items: %d\n", order.numItems);
    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d: %s - $%.2lf\n", i+1, order.items[i].name, order.items[i].price);
    }
    printf("Total Price: $%.2lf\n", calculateTotal(order));
    printf("\n");
}

int main() {
    Order order;
    order.numItems = 0;

    // Get the number of menu items from the user
    int numMenuItems;
    printf("Enter the number of menu items: ");
    scanf("%d", &numMenuItems);

    // Add menu items to the order
    for (int i = 0; i < numMenuItems; i++) {
        addItem(&order);
    }

    // Print the order details
    printOrder(order);

    return 0;
}