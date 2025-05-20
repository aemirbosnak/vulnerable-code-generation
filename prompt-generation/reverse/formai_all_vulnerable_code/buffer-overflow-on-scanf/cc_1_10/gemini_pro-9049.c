//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure to store cafe items
typedef struct {
    char name[50];
    float price;
} Item;

// Structure to store an order
typedef struct {
    Item item;
    int quantity;
} Order;

// Function to add an item to an order
void addItem(Order *order, Item item, int quantity) {
    order->item = item;
    order->quantity = quantity;
}

// Function to calculate the total cost of an order
float calculateTotal(Order *orders, int numOrders) {
    float total = 0;
    for (int i = 0; i < numOrders; i++) {
        total += orders[i].item.price * orders[i].quantity;
    }
    return total;
}

// Function to print an order
void printOrder(Order order) {
    printf("%s\t%.2f\t%d\n", order.item.name, order.item.price, order.quantity);
}

// Function to print all orders
void printAllOrders(Order *orders, int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        printOrder(orders[i]);
    }
}

// Function to get user input for an item
Item getItemInput() {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    return item;
}

// Function to get user input for an order
Order getOrderInput() {
    Order order;
    order.item = getItemInput();
    printf("Enter quantity: ");
    scanf("%d", &order.quantity);
    return order;
}

// Main function
int main() {
    // Create an array of items
    Item items[] = {
        {"Coffee", 2.50},
        {"Tea", 2.00},
        {"Cake", 4.00},
        {"Muffin", 3.00}
    };

    // Get the number of items in the cafe
    int numItems = sizeof(items) / sizeof(items[0]);

    // Get the number of orders
    int numOrders;
    printf("Enter the number of orders: ");
    scanf("%d", &numOrders);

    // Create an array of orders
    Order orders[numOrders];

    // Get user input for each order
    for (int i = 0; i < numOrders; i++) {
        orders[i] = getOrderInput();
    }

    // Calculate the total cost of the orders
    float totalCost = calculateTotal(orders, numOrders);

    // Print the orders
    printf("\nOrders:\n");
    printAllOrders(orders, numOrders);

    // Print the total cost
    printf("\nTotal cost: %.2f\n", totalCost);

    return 0;
}