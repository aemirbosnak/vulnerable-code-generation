//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Soda", 1.50},
    {"Water", 1.00},
    {"Cake", 3.00},
    {"Pie", 3.50},
    {"Cookie", 1.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
    struct MenuItem item;
    int quantity;
};

// Function to print the menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menu) / sizeof(struct MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the user's order
struct Order getOrder() {
    struct Order order;

    // Get the item number
    int itemNumber;
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &itemNumber);

    // Get the quantity
    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Set the order item and quantity
    order.item = menu[itemNumber - 1];
    order.quantity = quantity;

    return order;
}

// Function to calculate the total price of an order
float calculateTotalPrice(struct Order orders[], int numOrders) {
    float totalPrice = 0;
    for (int i = 0; i < numOrders; i++) {
        totalPrice += orders[i].item.price * orders[i].quantity;
    }
    return totalPrice;
}

// Function to print the receipt
void printReceipt(struct Order orders[], int numOrders, float totalPrice) {
    printf("Receipt:\n");
    for (int i = 0; i < numOrders; i++) {
        printf("%s x %d - $%.2f\n", orders[i].item.name, orders[i].quantity, orders[i].item.price * orders[i].quantity);
    }
    printf("Total: $%.2f\n", totalPrice);
}

// Main function
int main() {
    // Print the menu
    printMenu();

    // Get the user's order
    struct Order orders[MAX_ITEMS];
    int numOrders = 0;
    char anotherOrder;
    do {
        orders[numOrders] = getOrder();
        numOrders++;

        // Ask the user if they want to order another item
        printf("Do you want to order another item? (y/n) ");
        scanf(" %c", &anotherOrder);
    } while (anotherOrder == 'y');

    // Calculate the total price of the order
    float totalPrice = calculateTotalPrice(orders, numOrders);

    // Print the receipt
    printReceipt(orders, numOrders, totalPrice);

    return 0;
}