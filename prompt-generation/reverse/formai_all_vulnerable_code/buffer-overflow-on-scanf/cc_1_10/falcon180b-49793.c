//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the struct for the order
typedef struct {
    int numItems;
    MenuItem items[10];
} Order;

// Function to add a menu item to the order
void addItem(Order* order) {
    int numItems = order->numItems;
    printf("Enter the name of the item: ");
    scanf("%s", order->items[numItems].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[numItems].price);
    numItems++;
    order->numItems = numItems;
}

// Function to display the order
void displayOrder(Order order) {
    printf("\nOrder:\n");
    printf("------------------------\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("Item %d: %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }
    printf("------------------------\n");
}

// Function to calculate the total price of the order
float calculateTotal(Order order) {
    float total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Main function
int main() {
    Order order;
    order.numItems = 0;

    // Add menu items to the order
    addItem(&order);
    addItem(&order);

    // Display the order
    displayOrder(order);

    // Calculate the total price of the order
    float total = calculateTotal(order);

    // Display the total price
    printf("\nTotal price: $%.2f\n", total);

    return 0;
}