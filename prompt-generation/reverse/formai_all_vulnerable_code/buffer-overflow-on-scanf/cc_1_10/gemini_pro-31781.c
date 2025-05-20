//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

// Define the menu
struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Muffin", 2.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the order struct
struct Order {
    char customerName[50];
    struct MenuItem items[MAX_ITEMS];
    int numItems;
    float total;
};

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menu) / sizeof(struct MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the customer's order
struct Order getOrder() {
    struct Order order;

    // Get the customer's name
    printf("Enter your name: ");
    scanf("%s", order.customerName);

    // Get the number of items the customer wants to order
    printf("How many items would you like to order? ");
    scanf("%d", &order.numItems);

    // Get the items the customer wants to order
    for (int i = 0; i < order.numItems; i++) {
        int itemNumber;
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &itemNumber);

        // Check if the item number is valid
        if (itemNumber < 1 || itemNumber > sizeof(menu) / sizeof(struct MenuItem)) {
            printf("Invalid item number. Please enter a number between 1 and %d.\n", sizeof(menu) / sizeof(struct MenuItem));
            i--;
            continue;
        }

        // Add the item to the order
        order.items[i] = menu[itemNumber - 1];
    }

    // Calculate the total price of the order
    order.total = 0;
    for (int i = 0; i < order.numItems; i++) {
        order.total += order.items[i].price;
    }

    return order;
}

// Function to print the order
void printOrder(struct Order order) {
    printf("Order for %s:\n", order.customerName);
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", order.total);
}

// Function to get the payment from the customer
float getPayment(struct Order order) {
    float payment;
    printf("Your total is $%.2f. How much would you like to pay? ", order.total);
    scanf("%f", &payment);

    // Check if the payment is valid
    while (payment < order.total) {
        printf("Your payment is less than the total. Please enter a valid payment amount: ");
        scanf("%f", &payment);
    }

    return payment;
}

// Function to print the receipt
void printReceipt(struct Order order, float payment) {
    printf("Receipt for %s:\n", order.customerName);
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", order.total);
    printf("Payment: $%.2f\n", payment);
    printf("Change: $%.2f\n", payment - order.total);
}

// Main function
int main() {
    // Print the menu
    printMenu();

    // Get the customer's order
    struct Order order = getOrder();

    // Print the order
    printOrder(order);

    // Get the payment from the customer
    float payment = getPayment(order);

    // Print the receipt
    printReceipt(order, payment);

    return 0;
}