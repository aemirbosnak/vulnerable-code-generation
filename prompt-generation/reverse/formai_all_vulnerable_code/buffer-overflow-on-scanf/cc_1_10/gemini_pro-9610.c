//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the menu items and their prices
typedef struct MenuItem {
    char name[50];
    double price;
} MenuItem;

MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Soda", 1.75},
    {"Juice", 2.00},
    {"Muffin", 2.25},
    {"Cookie", 1.00},
    {"Bagel", 2.75},
    {"Sandwich", 4.50}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
typedef struct Order {
    int num_items;
    MenuItem items[MAX_ITEMS];
    double total_price;
} Order;

// Function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < sizeof(menu) / sizeof(MenuItem); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get the user's order
Order get_order() {
    Order order;
    order.num_items = 0;
    order.total_price = 0.0;

    printf("Enter the number of items you want to order: ");
    scanf("%d", &order.num_items);

    for (int i = 0; i < order.num_items; i++) {
        printf("Enter the number of the item you want to order: ");
        int item_num;
        scanf("%d", &item_num);

        order.items[i] = menu[item_num - 1];
        order.total_price += order.items[i].price;
    }

    return order;
}

// Function to print the order
void print_order(Order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, order.items[i].name, order.items[i].price);
    }
    printf("Total price: $%.2f\n", order.total_price);
}

// Function to get the payment information
void get_payment(Order order) {
    printf("Enter the amount you are paying with: ");
    double payment;
    scanf("%lf", &payment);

    if (payment < order.total_price) {
        printf("Insufficient payment. Please try again.\n");
        get_payment(order);
    } else {
        printf("Thank you for your payment. Your change is $%.2f\n", payment - order.total_price);
    }
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's order
    Order order = get_order();

    // Print the order
    print_order(order);

    // Get the payment information
    get_payment(order);

    return 0;
}