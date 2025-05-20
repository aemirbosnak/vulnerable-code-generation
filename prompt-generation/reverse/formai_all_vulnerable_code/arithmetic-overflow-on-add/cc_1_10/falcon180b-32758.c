//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the prices of the menu items
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.50
#define CAKE_PRICE 3.50

// Define the maximum number of items a customer can order
#define MAX_ITEMS 10

// Define the structure of a menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    MenuItem items[MAX_ITEMS];
    int numItems;
    double totalPrice;
} Order;

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Cafe!\n");
    printf("Please choose your items from the menu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Cake - $3.50\n");
}

// Function to add an item to the order
void addItem(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: $");
    scanf("%lf", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to calculate the total price of the order
void calculateTotal(Order* order) {
    order->totalPrice = 0.0;
    for (int i = 0; i < order->numItems; i++) {
        order->totalPrice += order->items[i].price;
    }
}

// Function to print the order details
void printOrder(Order* order) {
    printf("Order details:\n");
    printf("--------------------\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2lf\n", order->items[i].name, order->items[i].price);
    }
    printf("Total price: $%.2lf\n", order->totalPrice);
}

// Main function
int main() {
    Order order;
    order.numItems = 0;
    while (order.numItems < MAX_ITEMS) {
        displayMenu();
        printf("Enter 1 to add an item or 0 to proceed to payment:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addItem(&order);
        } else if (choice == 0) {
            calculateTotal(&order);
            printOrder(&order);
            printf("Thank you for your order! Please pay $%.2lf.\n", order.totalPrice);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}