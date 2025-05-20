//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 100

// Define the menu items and their prices
char *menu_items[] = {
    "Coffee", "Tea", "Soda", "Water", "Muffin", "Cookie", "Scone"
};
double menu_prices[] = {
    1.50, 1.25, 1.00, 0.50, 2.00, 1.00, 1.50
};

// Define the order structure
typedef struct order {
    int num_items;
    char *items[MAX_ITEMS];
    double prices[MAX_ITEMS];
    double total;
} order_t;

// Create a new order
order_t *create_order() {
    order_t *order = malloc(sizeof(order_t));
    order->num_items = 0;
    order->total = 0.0;
    return order;
}

// Add an item to an order
void add_item_to_order(order_t *order, char *item, double price) {
    if (order->num_items < MAX_ITEMS) {
        order->items[order->num_items] = item;
        order->prices[order->num_items] = price;
        order->total += price;
        order->num_items++;
    } else {
        printf("Error: The order is full. Cannot add more items.\n");
    }
}

// Print an order
void print_order(order_t *order) {
    printf("Order Summary:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("Item: %s, Price: $%.2f\n", order->items[i], order->prices[i]);
    }
    printf("Total: $%.2f\n", order->total);
}

// Get the user's input
int get_user_input(char *prompt, char *input) {
    printf("%s", prompt);
    return scanf("%s", input);
}

// Main function
int main() {
    // Create a new order
    order_t *order = create_order();

    // Get the user's input
    char input[100];
    int done = 0;
    while (!done) {
        // Prompt the user for an item
        get_user_input("Enter an item (or 'q' to quit): ", input);

        // Check if the user wants to quit
        if (strcmp(input, "q") == 0) {
            done = 1;
        } else {
            // Find the item in the menu
            int item_index = -1;
            for (int i = 0; i < 7; i++) {
                if (strcmp(input, menu_items[i]) == 0) {
                    item_index = i;
                    break;
                }
            }

            // If the item was found, add it to the order
            if (item_index != -1) {
                add_item_to_order(order, menu_items[item_index], menu_prices[item_index]);
            } else {
                printf("Error: Invalid item. Please try again.\n");
            }
        }
    }

    // Print the order summary
    print_order(order);

    // Free the memory allocated for the order
    free(order);

    return 0;
}