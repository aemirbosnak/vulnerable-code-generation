//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a menu item
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Define the structure of a customer order
typedef struct {
    char name[50];
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

// Function to calculate the total cost of the order
double calculateTotal(CustomerOrder* order) {
    double total = 0;
    for (int i = 0; i < order->numItems; i++) {
        total += order->items[i].price;
    }
    return total;
}

// Function to print the order details
void printOrder(CustomerOrder* order) {
    printf("Customer name: %s\n", order->name);
    printf("Number of items: %d\n", order->numItems);
    for (int i = 0; i < order->numItems; i++) {
        printf("Item %d: %s - $%.2lf\n", i+1, order->items[i].name, order->items[i].price);
    }
    printf("Total cost: $%.2lf\n", calculateTotal(order));
}

int main() {
    CustomerOrder order;
    printf("Enter the customer name: ");
    scanf("%s", order.name);

    // Add menu items to the order
    addItem(&order);
    addItem(&order);
    addItem(&order);

    // Print the order details
    printOrder(&order);

    return 0;
}