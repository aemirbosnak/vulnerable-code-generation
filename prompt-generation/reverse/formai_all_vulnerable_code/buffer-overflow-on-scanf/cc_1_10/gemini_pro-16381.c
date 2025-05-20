//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menuItems[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Hot Chocolate", 2.00},
    {"Muffin", 3.00},
    {"Scone", 2.50},
    {"Cookie", 1.00},
    {"Cake", 4.00},
    {"Pie", 3.50},
    {"Juice", 2.00},
    {"Soda", 1.50}
};

// Define the order structure
struct Order {
    char customerName[50];
    int numItems;
    struct MenuItem items[MAX_ITEMS];
    float total;
};

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menuItems) / sizeof(struct MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to get the customer's name
void getCustomerName(char *customerName) {
    printf("Enter your name: ");
    gets(customerName);
}

// Function to get the customer's order
void getOrder(struct Order *order) {
    int numItems;
    printf("How many items would you like to order? ");
    scanf("%d", &numItems);
    order->numItems = numItems;

    for (int i = 0; i < numItems; i++) {
        int itemNumber;
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &itemNumber);
        order->items[i] = menuItems[itemNumber - 1];
    }
}

// Function to calculate the total cost of the order
void calculateTotal(struct Order *order) {
    order->total = 0;
    for (int i = 0; i < order->numItems; i++) {
        order->total += order->items[i].price;
    }
}

// Function to print the receipt
void printReceipt(struct Order *order) {
    printf("\nReceipt:\n");
    printf("Customer Name: %s\n", order->customerName);
    printf("Items Ordered:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", order->total);
}

// Main function
int main() {
    struct Order order;

    // Print the menu
    printMenu();

    // Get the customer's name
    getCustomerName(order.customerName);

    // Get the customer's order
    getOrder(&order);

    // Calculate the total cost of the order
    calculateTotal(&order);

    // Print the receipt
    printReceipt(&order);

    return 0;
}