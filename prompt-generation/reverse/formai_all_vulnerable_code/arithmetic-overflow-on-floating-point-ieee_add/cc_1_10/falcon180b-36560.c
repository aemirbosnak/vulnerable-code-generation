//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for an order
typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to print the menu
void printMenu(MenuItem menuItems[], int numItems) {
    printf("\nMenu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take an order
void takeOrder(Order *order) {
    printf("\nEnter the number of items you would like to order (up to %d): ", MAX_ITEMS);
    scanf("%d", &order->numItems);

    for (int i = 0; i < order->numItems; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", order->items[i].name);

        printf("Enter the price of item %d: ", i+1);
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate the total cost of an order
float calculateTotal(Order order) {
    float total = 0.0;

    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }

    return total;
}

// Function to print an order
void printOrder(Order order) {
    printf("\nOrder:\n");

    for (int i = 0; i < order.numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }

    printf("\nTotal cost: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Muffin", 3.00},
        {"Bagel", 2.25}
    };

    // Define the order
    Order order;

    // Print the menu
    printMenu(menuItems, sizeof(menuItems)/sizeof(MenuItem));

    // Take the order
    takeOrder(&order);

    // Print the order
    printOrder(order);

    return 0;
}