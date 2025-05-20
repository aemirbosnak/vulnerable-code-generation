//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a menu item
struct menuItem {
    char name[50];
    float price;
};

// Define the structure of a customer order
struct customerOrder {
    int numItems;
    struct menuItem items[10]; // Maximum of 10 items per order
};

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Cafe!\n");
    printf("------------------------\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Sandwich\n");
    printf("4. Salad\n");
    printf("5. Cake\n");
    printf("------------------------\n");
}

// Function to take customer order
void takeOrder(struct customerOrder *order) {
    int i = 0;
    printf("Enter the number of items in your order: ");
    scanf("%d", &order->numItems);

    for (i = 0; i < order->numItems; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", order->items[i].name);
        printf("Enter the price of item %s: ", order->items[i].name);
        scanf("%f", &order->items[i].price);
    }
}

// Function to calculate total cost of order
float calculateTotal(struct customerOrder order) {
    float total = 0.0;
    int i;

    for (i = 0; i < order.numItems; i++) {
        total += order.items[i].price;
    }

    return total;
}

// Function to print customer order
void printOrder(struct customerOrder order) {
    int i;

    printf("Customer Order:\n");
    printf("------------------------\n");

    for (i = 0; i < order.numItems; i++) {
        printf("%s: $%.2f\n", order.items[i].name, order.items[i].price);
    }

    printf("Total Cost: $%.2f\n", calculateTotal(order));
    printf("------------------------\n");
}

// Function to handle billing and payment
void handleBilling(struct customerOrder order) {
    float total = calculateTotal(order);

    printf("Your total cost is: $%.2f\n", total);
    printf("Please pay the cashier.\n");
}

int main() {
    struct customerOrder order;

    displayMenu();
    takeOrder(&order);
    printOrder(order);
    handleBilling(order);

    return 0;
}