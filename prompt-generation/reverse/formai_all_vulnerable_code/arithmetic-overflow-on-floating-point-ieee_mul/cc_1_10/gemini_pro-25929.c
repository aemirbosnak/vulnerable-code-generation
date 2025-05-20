//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char menu_items[10][20] = {"Coffee", "Tea", "Juice", "Sandwich", "Pastry", "Cake", "Soup", "Salad", "Fruit", "Water"};
float menu_prices[10] = {1.50, 1.25, 1.75, 5.00, 3.00, 4.00, 4.50, 6.00, 3.50, 1.00};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct order_item {
    int item_id;
    int quantity;
    float price;
} order_item;

// Define the structure of an order
typedef struct order {
    int num_items;
    order_item items[MAX_ITEMS];
    float total_price;
} order;

// Function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu_items[i], menu_prices[i]);
    }
}

// Function to get the user's order
order get_order() {
    order new_order;
    new_order.num_items = 0;
    new_order.total_price = 0.0;

    // Get the number of items in the order
    printf("How many items would you like to order? ");
    scanf("%d", &new_order.num_items);

    // Get the details of each item in the order
    for (int i = 0; i < new_order.num_items; i++) {
        printf("Enter the item ID and quantity of item %d: ", i + 1);
        scanf("%d %d", &new_order.items[i].item_id, &new_order.items[i].quantity);

        // Calculate the price of the item
        new_order.items[i].price = menu_prices[new_order.items[i].item_id - 1] * new_order.items[i].quantity;

        // Add the price of the item to the total price of the order
        new_order.total_price += new_order.items[i].price;
    }

    return new_order;
}

// Function to print the order
void print_order(order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%d. %s x %d - $%.2f\n", i + 1, menu_items[order.items[i].item_id - 1], order.items[i].quantity, order.items[i].price);
    }
    printf("Total price: $%.2f\n", order.total_price);
}

// Function to get the payment from the user
float get_payment(float total_price) {
    float payment;

    // Get the payment amount from the user
    printf("Enter the payment amount: $");
    scanf("%f", &payment);

    return payment;
}

// Function to print the receipt
void print_receipt(order order, float payment) {
    printf("Receipt:\n");
    print_order(order);
    printf("Payment: $%.2f\n", payment);
    printf("Change: $%.2f\n", payment - order.total_price);
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's order
    order order = get_order();

    // Print the order
    print_order(order);

    // Get the payment from the user
    float payment = get_payment(order.total_price);

    // Print the receipt
    print_receipt(order, payment);

    return 0;
}