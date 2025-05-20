//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items that can be stored in the order
#define MAX_ITEMS 100

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

// Function to display the menu
void displayMenu(MenuItem menuItems[], int numMenuItems) {
    printf("Welcome to the Cafe!\n");
    printf("Here's what we have on the menu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take an order
void takeOrder(Order* order) {
    printf("What would you like to order?\n");
    scanf("%d", &order->numItems);
    for (int i = 0; i < order->numItems; i++) {
        printf("Enter the name of item %d:\n", i+1);
        scanf("%s", order->items[i].name);
        printf("Enter the price of item %d:\n", i+1);
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate the total price of an order
float calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {{"Coffee", 3.50}, {"Tea", 2.50}, {"Latte", 4.00}, {"Cappuccino", 4.50}};
    int numMenuItems = sizeof(menuItems)/sizeof(MenuItem);

    // Initialize an order with no items
    Order order = {0, {{"", 0}}};

    // Display the menu
    displayMenu(menuItems, numMenuItems);

    // Take the order
    takeOrder(&order);

    // Calculate the total price of the order
    float total = calculateTotal(order);

    // Print the order details and total price
    printf("Your order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total price: $%.2f\n", total);

    return 0;
}