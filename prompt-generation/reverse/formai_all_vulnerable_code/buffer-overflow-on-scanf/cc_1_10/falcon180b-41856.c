//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure for an item in the order
typedef struct {
    char name[50];
    float price;
} Item;

// Define the structure for an order
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void addItem(Order* order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->items[order->numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[order->numItems].price);
    order->numItems++;
}

// Function to display the items in the order
void displayItems(Order* order) {
    printf("Order items:\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s: $%.2f\n", order->items[i].name, order->items[i].price);
    }
}

// Function to calculate the total price of the order
float calculateTotal(Order* order) {
    float total = 0;
    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].price;
    }
    return total;
}

// Function to generate a random order ID
int generateOrderID() {
    srand(time(0));
    return rand() % 1000000;
}

int main() {
    Order order;
    order.numItems = 0;

    // Add items to the order
    addItem(&order);
    addItem(&order);
    addItem(&order);

    // Display the items in the order
    displayItems(&order);

    // Calculate the total price of the order
    float total = calculateTotal(&order);
    printf("Total price of the order: $%.2f\n", total);

    // Generate a random order ID
    int orderID = generateOrderID();
    printf("Order ID: %d\n", orderID);

    return 0;
}