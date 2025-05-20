//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of a menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    int numItems;
    MenuItem items[MAX_ITEMS];
} CustomerOrder;

// Function to print the menu
void printMenu(MenuItem menuItems[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take customer order
void takeOrder(CustomerOrder *order) {
    printf("Please enter the number of items you want to order (max %d): ", MAX_ITEMS);
    scanf("%d", &order->numItems);

    for (int i = 0; i < order->numItems; i++) {
        printf("Please enter the name of item %d: ", i+1);
        scanf("%s", order->items[i].name);

        printf("Please enter the price of item %d: ", i+1);
        scanf("%lf", &order->items[i].price);
    }
}

// Function to calculate the total cost of an order
double calculateTotal(CustomerOrder order) {
    double total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the customer order
void printOrder(CustomerOrder order) {
    printf("Order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total cost: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Soda", 1.25}, {"Cake", 3.50}};

    // Define the customer order
    CustomerOrder order;

    // Print the menu
    printMenu(menuItems, 4);

    // Take the customer order
    takeOrder(&order);

    // Print the customer order
    printOrder(order);

    return 0;
}