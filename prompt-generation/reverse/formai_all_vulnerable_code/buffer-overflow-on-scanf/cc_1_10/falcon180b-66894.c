//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for the order
typedef struct {
    char customerName[50];
    int numItems;
    MenuItem items[10];
} Order;

// Function to print the menu
void printMenu(MenuItem menuItems[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take the order
void takeOrder(Order *order) {
    printf("Enter your name: ");
    scanf("%s", order->customerName);

    printf("How many items would you like to order? ");
    scanf("%d", &order->numItems);

    for (int i = 0; i < order->numItems; i++) {
        printf("Enter the name of the item: ");
        scanf("%s", order->items[i].name);

        printf("Enter the price of the item: ");
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate the total price of the order
float calculateTotal(Order order) {
    float total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the order
void printOrder(Order order) {
    printf("Order for %s:\n", order.customerName);
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total price: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu items
    MenuItem menuItems[] = {
        {"Coffee", 2.50},
        {"Tea", 1.50},
        {"Sandwich", 4.00},
        {"Cake", 3.00}
    };
    int numMenuItems = sizeof(menuItems)/sizeof(MenuItem);

    // Define the order
    Order order;

    // Print the menu
    printMenu(menuItems, numMenuItems);

    // Take the order
    takeOrder(&order);

    // Print the order
    printOrder(order);

    return 0;
}