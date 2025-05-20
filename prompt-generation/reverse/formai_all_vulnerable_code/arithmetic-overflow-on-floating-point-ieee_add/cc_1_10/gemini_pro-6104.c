//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu_items[][50] = {"Coffee", "Tea", "Cold Drink", "Sandwich", "Pastry"};
float menu_prices[] = {2.0, 1.5, 1.2, 3.0, 2.5};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct {
    int item_code;
    int quantity;
} order_item;

// Define the structure of an order
typedef struct {
    order_item items[MAX_ITEMS];
    int num_items;
    float total_price;
} order;

// Function to print the menu
void print_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - %.2f\n", i + 1, menu_items[i], menu_prices[i]);
    }
}

// Function to get the order from the user
order get_order() {
    order order;
    order.num_items = 0;
    order.total_price = 0.0;

    int item_code;
    int quantity;

    while (1) {
        printf("Enter the item code (0 to finish): ");
        scanf("%d", &item_code);

        if (item_code == 0) {
            break;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        // Add the item to the order
        order.items[order.num_items].item_code = item_code;
        order.items[order.num_items].quantity = quantity;
        order.num_items++;

        // Update the total price
        order.total_price += menu_prices[item_code - 1] * quantity;
    }

    return order;
}

// Function to print the order
void print_order(order order) {
    printf("Order:\n");
    for (int i = 0; i < order.num_items; i++) {
        printf("%d. %s - %d x %.2f = %.2f\n", i + 1, menu_items[order.items[i].item_code - 1], order.items[i].quantity, menu_prices[order.items[i].item_code - 1], order.items[i].quantity * menu_prices[order.items[i].item_code - 1]);
    }
    printf("Total: %.2f\n", order.total_price);
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the order from the user
    order order = get_order();

    // Print the order
    print_order(order);

    return 0;
}