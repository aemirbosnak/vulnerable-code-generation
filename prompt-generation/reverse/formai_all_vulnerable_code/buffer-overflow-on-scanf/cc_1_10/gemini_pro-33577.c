//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
    char name[50];
    float price;
};

struct MenuItem menu[] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Cake", 3.00},
    {"Muffin", 2.00}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
struct Order {
    int item_count;
    struct MenuItem items[MAX_ITEMS];
};

// Get the user's input
void get_input(struct Order *order) {
    int i;

    // Get the number of items ordered
    printf("How many items would you like to order? ");
    scanf("%d", &order->item_count);

    // Get the items ordered
    for (i = 0; i < order->item_count; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", order->items[i].name);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &order->items[i].price);
    }
}

// Calculate the total price of the order
float calculate_total(struct Order *order) {
    int i;
    float total = 0.0;

    for (i = 0; i < order->item_count; i++) {
        total += order->items[i].price;
    }

    return total;
}

// Print the order
void print_order(struct Order *order) {
    int i;

    printf("Your order:\n");

    for (i = 0; i < order->item_count; i++) {
        printf("%s: %f\n", order->items[i].name, order->items[i].price);
    }

    printf("Total: %f\n", calculate_total(order));
}

// Main function
int main() {
    struct Order order;

    // Get the user's input
    get_input(&order);

    // Calculate the total price of the order
    float total = calculate_total(&order);

    // Print the order
    print_order(&order);

    return 0;
}