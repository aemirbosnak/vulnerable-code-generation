//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure for a customer order
typedef struct {
    int numItems;
    MenuItem items[10]; // Maximum of 10 items per order
} CustomerOrder;

// Function to add a menu item to the order
void addItem(CustomerOrder* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to print the customer order
void printOrder(CustomerOrder order) {
    printf("\nOrder Summary:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%s - $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("\nTotal: $%.2f\n", order.items[0].price * order.numItems);
}

// Function to calculate the total price of the order
float calculateTotal(CustomerOrder order) {
    return order.items[0].price * order.numItems;
}

// Main function
int main() {
    // Initialize variables
    CustomerOrder order;
    order.numItems = 0;

    // Add menu items to the order
    addItem(&order);
    addItem(&order);

    // Print the order summary
    printOrder(order);

    // Calculate the total price of the order
    float totalPrice = calculateTotal(order);

    // Display the total price to the customer
    printf("\nTotal price: $%.2f\n", totalPrice);

    return 0;
}