//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define the structure for each item in the order
typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

// Define the structure for the order
typedef struct {
    char customerName[50];
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void addItem(Order *order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &order->items[order->numItems].quantity);
    order->numItems++;
}

// Function to display the order details
void displayOrder(Order order) {
    printf("Customer Name: %s\n", order.customerName);
    printf("Number of Items: %d\n", order.numItems);
    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", order.items[i].name);
        printf("Price: $%.2f\n", order.items[i].price);
        printf("Quantity: %d\n\n", order.items[i].quantity);
    }
}

// Function to calculate the total cost of the order
float calculateTotalCost(Order order) {
    float totalCost = 0.0;
    for (int i = 0; i < order.numItems; i++) {
        totalCost += order.items[i].price * order.items[i].quantity;
    }
    return totalCost;
}

int main() {
    Order order;
    strcpy(order.customerName, "John Doe");
    order.numItems = 0;

    // Add items to the order
    addItem(&order);
    addItem(&order);

    // Display the order details
    displayOrder(order);

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost(order);
    printf("Total Cost: $%.2f\n", totalCost);

    return 0;
}