//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
/*
 * Cafe Billing System
 *
 * This program is a simple billing system for a cafe.
 * It allows customers to select a menu item and pay for it.
 * The program also calculates the total cost of the order and
 * displays a receipt.
 */

#include <stdio.h>

// Define the menu items
#define MENU_ITEMS 5

typedef struct {
    char name[20];
    double price;
} menu_item;

menu_item menu[MENU_ITEMS] = {
    {"Coffee", 2.50},
    {"Tea", 1.50},
    {"Sandwich", 5.00},
    {"Salad", 4.50},
    {"Dessert", 3.00}
};

int main() {
    // Declare variables
    int selection;
    double total_cost = 0.0;
    char name[20];

    // Print the menu
    printf("Welcome to our cafe!\n");
    printf("Menu:\n");
    for (int i = 0; i < MENU_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }

    // Take order
    printf("What would you like to order? ");
    scanf("%d", &selection);

    // Calculate total cost
    total_cost += menu[selection - 1].price;

    // Print receipt
    printf("Thank you for your order!\n");
    printf("You have ordered: %s\n", menu[selection - 1].name);
    printf("Total cost: $%.2f\n", total_cost);

    return 0;
}