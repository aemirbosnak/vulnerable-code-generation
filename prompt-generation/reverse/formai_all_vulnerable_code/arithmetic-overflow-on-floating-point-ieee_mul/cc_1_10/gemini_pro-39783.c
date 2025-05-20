//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu[][20] = {"Coffee", "Tea", "Sandwich", "Pastry"};
float prices[] = {2.50, 1.50, 5.00, 3.00};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the data structure for an order
struct order {
    char items[MAX_ITEMS][20];
    float quantities[MAX_ITEMS];
    float total_price;
};

// Function to display the menu
void display_menu() {
    printf("Menu:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
}

// Function to get the user's order
struct order get_order() {
    struct order order;
    int num_items;

    // Get the number of items ordered
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    // Get the items and quantities ordered
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", order.items[i]);
        printf("Quantity: ");
        scanf("%f", &order.quantities[i]);
    }

    // Calculate the total price of the order
    order.total_price = 0;
    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < 4; j++) {
            if (strcmp(order.items[i], menu[j]) == 0) {
                order.total_price += order.quantities[i] * prices[j];
            }
        }
    }

    return order;
}

// Function to print the receipt
void print_receipt(struct order order) {
    printf("Receipt:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s x %.2f - $%.2f\n", order.items[i], order.quantities[i], order.quantities[i] * prices[i]);
    }
    printf("Total: $%.2f\n", order.total_price);
}

// Main function
int main() {
    // Display the menu
    display_menu();

    // Get the user's order
    struct order order = get_order();

    // Print the receipt
    print_receipt(order);

    return 0;
}