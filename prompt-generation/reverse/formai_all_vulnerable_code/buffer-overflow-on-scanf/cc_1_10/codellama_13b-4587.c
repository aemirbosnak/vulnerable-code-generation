//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
// C Cafe Billing System Example Program

#include <stdio.h>

// Define the menu items and their prices
#define ITEM_1 "Coffee"
#define ITEM_2 "Tea"
#define ITEM_3 "Soda"
#define ITEM_4 "Cappuccino"
#define ITEM_5 "Espresso"
#define PRICE_1 2.00
#define PRICE_2 1.50
#define PRICE_3 2.50
#define PRICE_4 3.00
#define PRICE_5 3.50

// Define the struct to store the menu items and their prices
typedef struct {
    char *name;
    double price;
} menu_item;

// Define an array of menu items
menu_item menu[] = {
    {ITEM_1, PRICE_1},
    {ITEM_2, PRICE_2},
    {ITEM_3, PRICE_3},
    {ITEM_4, PRICE_4},
    {ITEM_5, PRICE_5}
};

// Define the number of menu items
#define NUM_MENU_ITEMS 5

// Define the struct to store the order details
typedef struct {
    char *item_name;
    double item_price;
    int quantity;
    double total_price;
} order;

// Define the function to calculate the total price of an order
double calculate_total_price(order *order) {
    return order->quantity * order->item_price;
}

// Define the function to display the menu
void display_menu() {
    printf("C Cafe Menu\n");
    printf("===========\n");
    for (int i = 0; i < NUM_MENU_ITEMS; i++) {
        printf("%s\t%.2f\n", menu[i].name, menu[i].price);
    }
}

// Define the function to take an order
void take_order(order *order) {
    printf("Enter the name of the item: ");
    scanf("%s", order->item_name);
    printf("Enter the quantity: ");
    scanf("%d", &order->quantity);
}

// Define the function to display the order
void display_order(order *order) {
    printf("Order Details\n");
    printf("============\n");
    printf("Item: %s\n", order->item_name);
    printf("Quantity: %d\n", order->quantity);
    printf("Total Price: %.2f\n", calculate_total_price(order));
}

// Define the function to calculate the total price of all orders
double calculate_total_price_of_all_orders(order *orders, int num_orders) {
    double total_price = 0.0;
    for (int i = 0; i < num_orders; i++) {
        total_price += calculate_total_price(&orders[i]);
    }
    return total_price;
}

// Define the function to display the total price of all orders
void display_total_price_of_all_orders(order *orders, int num_orders) {
    double total_price = calculate_total_price_of_all_orders(orders, num_orders);
    printf("Total Price of All Orders: %.2f\n", total_price);
}

// Define the main function
int main() {
    // Declare an array of orders
    order orders[10];

    // Take orders from the user
    for (int i = 0; i < 10; i++) {
        take_order(&orders[i]);
    }

    // Display the menu
    display_menu();

    // Display the orders
    for (int i = 0; i < 10; i++) {
        display_order(&orders[i]);
    }

    // Calculate and display the total price of all orders
    display_total_price_of_all_orders(orders, 10);

    return 0;
}