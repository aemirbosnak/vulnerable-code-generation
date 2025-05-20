//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the menu items and their prices
char menu_items[][255] = {
    "Espresso",
    "Cappuccino",
    "Latte",
    "Mocha",
    "Americano",
    "Tea",
    "Hot Chocolate",
};

float menu_prices[] = {
    1.50,
    2.00,
    2.50,
    3.00,
    2.00,
    1.50,
    2.00,
};

// Declare the function to calculate the total bill amount
float calculate_bill_amount(int item_count, int item_quantities[]) {
    float total_bill_amount = 0.0;

    // Loop through the menu items and their quantities
    for (int i = 0; i < item_count; i++) {
        // Calculate the total price for each menu item
        float item_total_price = menu_prices[i] * item_quantities[i];

        // Add the total price for each menu item to the total bill amount
        total_bill_amount += item_total_price;
    }

    // Return the total bill amount
    return total_bill_amount;
}

// Print the menu
void print_menu() {
    printf("\nMenu:\n");
    for (int i = 0; i < sizeof(menu_items) / sizeof(char*); i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu_items[i], menu_prices[i]);
    }
}

// Get the user's order
void get_order(int* item_quantities) {
    printf("\nWhat would you like to order?\n");

    int item_count;
    printf("How many items would you like to order: ");
    scanf("%d", &item_count);

    // Loop through the menu items and get the quantity for each item
    for (int i = 0; i < item_count; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &item_quantities[i]);
    }
}

// Print the bill
void print_bill(float total_bill_amount) {
    printf("\nYour Bill:\n");
    printf("Total Amount: $%.2f\n", total_bill_amount);
}

int main() {
    // Print a welcome message
    printf("Welcome to the Cafe Billing System!\n");

    // Print the menu
    print_menu();

    // Get the user's order
    int item_quantities[sizeof(menu_prices) / sizeof(float)];
    get_order(item_quantities);

    // Calculate the total bill amount
    float total_bill_amount = calculate_bill_amount(sizeof(menu_prices) / sizeof(float), item_quantities);

    // Print the bill
    print_bill(total_bill_amount);

    // Print a thank you message
    printf("\nThank you for dining with us!\n");

    return 0;
}