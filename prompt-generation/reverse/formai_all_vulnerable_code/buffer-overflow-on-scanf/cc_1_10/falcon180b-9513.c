//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for each item in the order
typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

// Define the structure for the order
typedef struct {
    char customerName[20];
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void addItem(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &order->items[order->numItems].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to calculate the total cost of the order
float calculateTotal(Order order) {
    float total = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        total += (order.items[i].quantity * order.items[i].price);
    }
    return total;
}

// Function to print the details of the order
void printOrder(Order order) {
    printf("Customer Name: %s\n", order.customerName);
    printf("Number of Items: %d\n", order.numItems);
    printf("Item Details:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("Name: %s\n", order.items[i].name);
        printf("Quantity: %d\n", order.items[i].quantity);
        printf("Price: $%.2f\n", order.items[i].price);
        printf("Total Cost: $%.2f\n\n", order.items[i].quantity * order.items[i].price);
    }
    printf("Total Cost of the Order: $%.2f\n", calculateTotal(order));
}

int main() {
    Order order;

    // Get the customer name
    printf("Enter the name of the customer: ");
    scanf("%s", order.customerName);

    // Add items to the order
    int numItems = 0;
    while (numItems < MAX_ITEMS) {
        addItem(&order);
        numItems++;
    }

    // Print the order details
    printOrder(order);

    return 0;
}