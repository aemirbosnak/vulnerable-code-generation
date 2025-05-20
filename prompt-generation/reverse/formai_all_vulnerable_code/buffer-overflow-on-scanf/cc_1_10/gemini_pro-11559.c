//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: real-life
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
    {"Cake", 3.00},
    {"Muffin", 2.50},
    {"Sandwich", 5.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
    int item_count;
    struct MenuItem items[MAX_ITEMS];
    float total_price;
};

// Get the user's input and create an order
struct Order create_order() {
    struct Order order;
    
    printf("Welcome to the cafe!\n");
    printf("What would you like to order?\n");

    // Get the number of items that the user wants to order
    printf("Enter the number of items you want to order: ");
    scanf("%d", &order.item_count);

    // Get the items that the user wants to order
    for (int i = 0; i < order.item_count; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", order.items[i].name);
        
        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &order.items[i].price);
    }

    // Calculate the total price of the order
    order.total_price = 0;
    for (int i = 0; i < order.item_count; i++) {
        order.total_price += order.items[i].price;
    }

    return order;
}

// Print the order
void print_order(struct Order order) {
    printf("Your order:\n");
    for (int i = 0; i < order.item_count; i++) {
        printf("%s: $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total: $%.2f\n", order.total_price);
}

// Get the payment from the user
float get_payment() {
    float payment;
    
    printf("Enter your payment: ");
    scanf("%f", &payment);

    return payment;
}

// Main function
int main() {
    // Create an order
    struct Order order = create_order();

    // Print the order
    print_order(order);

    // Get the payment
    float payment = get_payment();

    // Calculate the change
    float change = payment - order.total_price;

    // Print the change
    printf("Your change: $%.2f\n", change);

    return 0;
}