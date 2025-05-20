//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define the structure of an item in the menu
typedef struct {
    char name[50];
    double price;
} Item;

// Define the structure of an order
typedef struct {
    int numItems;
    Item items[MAX_ITEMS];
} Order;

// Function to add an item to an order
void addItem(Order* order, Item item) {
    if (order->numItems >= MAX_ITEMS) {
        printf("Error: Cannot add more than %d items to an order.\n", MAX_ITEMS);
        return;
    }
    order->items[order->numItems] = item;
    order->numItems++;
}

// Function to calculate the total price of an order
double calculateTotal(Order order) {
    double total = 0;
    for (int i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }
    return total;
}

// Function to display the menu and take the customer's order
void takeOrder(Item menu[], int numMenuItems, Order* order) {
    printf("Welcome to the cafe!\n");
    printf("Please select your items from the following menu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > numMenuItems) {
        printf("Invalid choice.\n");
        return;
    }
    addItem(order, menu[choice-1]);
}

// Function to display the order and total price
void displayOrder(Order order) {
    printf("Your order:\n");
    for (int i = 0; i < order.numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, order.items[i].name, order.items[i].price);
    }
    printf("Total price: $%.2f\n", calculateTotal(order));
}

int main() {
    // Define the menu
    Item menu[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Sandwich", 4.25}, {"Cake", 3.00}};
    int numMenuItems = sizeof(menu)/sizeof(menu[0]);

    // Initialize the order
    Order order = {0};

    // Take the customer's order
    takeOrder(menu, numMenuItems, &order);

    // Display the order and total price
    displayOrder(order);

    return 0;
}