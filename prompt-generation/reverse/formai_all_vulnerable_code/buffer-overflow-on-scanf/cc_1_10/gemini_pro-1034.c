//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the menu items
#define COFFEE 1
#define TEA 2
#define CAKE 3

// Define the prices
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.50
#define CAKE_PRICE 3.00

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct {
    int item_id;
    int quantity;
} order_item;

// Define the structure of an order
typedef struct {
    order_item items[MAX_ITEMS];
    int num_items;
    double total_price;
} order;

// Create a new order
order* create_order() {
    order* new_order = malloc(sizeof(order));
    new_order->num_items = 0;
    new_order->total_price = 0.0;
    return new_order;
}

// Add an item to an order
void add_item_to_order(order* order, int item_id, int quantity) {
    if (order->num_items < MAX_ITEMS) {
        order->items[order->num_items].item_id = item_id;
        order->items[order->num_items].quantity = quantity;
        order->num_items++;

        // Update the total price of the order
        switch (item_id) {
            case COFFEE:
                order->total_price += COFFEE_PRICE * quantity;
                break;
            case TEA:
                order->total_price += TEA_PRICE * quantity;
                break;
            case CAKE:
                order->total_price += CAKE_PRICE * quantity;
                break;
        }
    }
}

// Print an order
void print_order(order* order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        switch (order->items[i].item_id) {
            case COFFEE:
                printf(" - %d Coffee(s)\n", order->items[i].quantity);
                break;
            case TEA:
                printf(" - %d Tea(s)\n", order->items[i].quantity);
                break;
            case CAKE:
                printf(" - %d Cake(s)\n", order->items[i].quantity);
                break;
        }
    }
    printf("Total Price: $%.2f\n", order->total_price);
}

// Get the user's order
order* get_user_order() {
    order* new_order = create_order();

    int choice = 0;
    int quantity = 0;
    while (choice != 4) {
        printf("1. Coffee ($2.50)\n");
        printf("2. Tea ($1.50)\n");
        printf("3. Cake ($3.00)\n");
        printf("4. Checkout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            add_item_to_order(new_order, choice, quantity);
        }
    }

    return new_order;
}

// Process the user's order
void process_order(order* order) {
    print_order(order);

    // Get payment from the user
    double payment = 0.0;
    printf("Enter payment amount: ");
    scanf("%lf", &payment);

    // Calculate the change
    double change = payment - order->total_price;

    // Print the receipt
    printf("Receipt:\n");
    print_order(order);
    printf("Payment: $%.2f\n", payment);
    printf("Change: $%.2f\n", change);
}

// Main function
int main() {
    order* user_order = get_user_order();
    process_order(user_order);

    return 0;
}