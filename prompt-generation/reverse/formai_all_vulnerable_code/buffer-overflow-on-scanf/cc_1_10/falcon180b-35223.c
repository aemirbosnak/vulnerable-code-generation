//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define the structure for an item in the menu
typedef struct {
    char name[50];
    float price;
} Item;

// Define the structure for an order
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to an order
void addItem(Order* order) {
    int i = 0;
    while (i < order->numItems && i < MAX_ITEMS) {
        printf("Enter the name of the item: ");
        scanf("%s", order->items[i].name);
        printf("Enter the price of the item: ");
        scanf("%f", &order->items[i].price);
        i++;
    }
    order->numItems = i;
}

// Function to calculate the total price of an order
float calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to print the details of an order
void printOrder(Order order) {
    printf("Order details:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d: %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }
    printf("Total price: $%.2f\n", calculateTotal(order));
}

int main() {
    Order order;
    addItem(&order);
    printOrder(order);
    return 0;
}