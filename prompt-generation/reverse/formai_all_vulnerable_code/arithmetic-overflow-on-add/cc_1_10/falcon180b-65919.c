//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    int numItems;
    MenuItem items[10];
} CustomerOrder;

// Function to add a menu item to the order
void addItem(CustomerOrder* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: $");
    scanf("%lf", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to remove a menu item from the order
void removeItem(CustomerOrder* order) {
    if (order->numItems == 0) {
        printf("There are no items in the order.\n");
        return;
    }
    order->numItems--;
}

// Function to display the customer order
void displayOrder(CustomerOrder* order) {
    printf("Order:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
}

// Function to calculate the total price of the order
double calculateTotal(CustomerOrder* order) {
    double total = 0.0;
    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].price;
    }
    return total;
}

// Function to print the receipt
void printReceipt(CustomerOrder* order, double total) {
    printf("\nReceipt:\n");
    printf("--------------------\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", total);
    printf("--------------------\n");
}

// Main function
int main() {
    // Initialize the customer order
    CustomerOrder order;
    order.numItems = 0;

    // Add menu items to the order
    addItem(&order);
    addItem(&order);

    // Remove a menu item from the order
    removeItem(&order);

    // Display the customer order
    displayOrder(&order);

    // Calculate the total price of the order
    double total = calculateTotal(&order);

    // Print the receipt
    printReceipt(&order, total);

    return 0;
}