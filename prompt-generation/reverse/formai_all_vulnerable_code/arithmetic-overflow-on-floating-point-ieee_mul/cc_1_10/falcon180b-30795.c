//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for orders
typedef struct {
    int numItems;
    MenuItem* items;
} Order;

// Function to print the menu
void printMenu(MenuItem* menu, int numItems) {
    printf("Welcome to the Happy Cafe!\n");
    printf("Here's our menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take an order
void takeOrder(Order* order) {
    printf("What would you like to order?\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, order->items[i].name, order->items[i].price);
    }
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &order->items[order->numItems].name);
    printf("Enter the quantity you want to order: ");
    scanf("%d", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to calculate the total price of an order
float calculateTotal(Order* order) {
    float total = 0.0;
    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].price * order->items[i].price;
    }
    return total;
}

// Function to print the order summary
void printSummary(Order* order) {
    printf("Here's your order summary:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f (x %d) = $%.2f\n", order->items[i].name, order->items[i].price, order->items[i].price, order->items[i].price * order->items[i].price);
    }
    printf("Total price: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menu[] = {{"Hamburger", 5.99}, {"Fries", 3.99}, {"Coke", 1.99}, {"Pizza", 9.99}};
    int numMenuItems = sizeof(menu) / sizeof(menu[0]);

    // Define the order
    Order order = {0, NULL};

    // Print the menu
    printMenu(menu, numMenuItems);

    // Take the order
    takeOrder(&order);

    // Print the order summary
    printSummary(&order);

    return 0;
}