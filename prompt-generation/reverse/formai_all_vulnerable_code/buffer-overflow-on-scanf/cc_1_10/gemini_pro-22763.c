//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 100

// Define the menu items and their prices
char menu_items[][50] = {
    "Espresso", "Cappuccino", "Latte", "Mocha", "Americano",
    "Tea", "Hot Chocolate", "Biscotti", "Muffin", "Bagel"
};
float menu_prices[] = {
    2.50, 3.00, 3.50, 4.00, 2.75,
    2.00, 3.25, 1.50, 2.00, 2.50
};

// Define the order structure
typedef struct order {
    int item_number;
    int quantity;
} order;

// Get the user's order
void get_order(order *order_list, int *num_items) {
    int item_number;
    int quantity;
    printf("Enter the item number and quantity (0 to exit): ");
    scanf("%d %d", &item_number, &quantity);
    while (item_number != 0) {
        order_list[*num_items].item_number = item_number;
        order_list[*num_items].quantity = quantity;
        (*num_items)++;
        printf("Enter the item number and quantity (0 to exit): ");
        scanf("%d %d", &item_number, &quantity);
    }
}

// Calculate the total price of the order
float calculate_total(order *order_list, int num_items) {
    float total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += menu_prices[order_list[i].item_number - 1] * order_list[i].quantity;
    }
    return total;
}

// Print the order receipt
void print_receipt(order *order_list, int num_items, float total) {
    printf("Cafe Billing System\n");
    printf("---------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s x%d\n", menu_items[order_list[i].item_number - 1], order_list[i].quantity);
    }
    printf("---------------------\n");
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Declare the order list and initialize the number of items to 0
    order order_list[MAX_ITEMS];
    int num_items = 0;

    // Get the user's order
    get_order(order_list, &num_items);

    // Calculate the total price of the order
    float total = calculate_total(order_list, num_items);

    // Print the order receipt
    print_receipt(order_list, num_items, total);

    return 0;
}