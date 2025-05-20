//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: careful
// Cafe Billing System

#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
char menu_items[][20] = {
    "Coffee",
    "Tea",
    "Espresso",
    "Cappuccino",
    "Latte",
    "Mocha",
    "Frappuccino",
    "Smoothie",
    "Juice",
    "Soda"
};

float menu_prices[] = {
    2.00,
    1.50,
    2.50,
    3.00,
    3.50,
    4.00,
    4.50,
    5.00,
    3.00,
    2.50
};

// Get the user's order
void get_order(int *num_items, int *item_codes, int *quantities) {
    printf("Welcome to the cafe!\n");
    printf("How many items would you like to order? ");
    scanf("%d", num_items);

    for (int i = 0; i < *num_items; i++) {
        printf("Enter the code of item %d: ", i + 1);
        scanf("%d", &item_codes[i]);
        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &quantities[i]);
    }
}

// Calculate the total bill
float calculate_bill(int num_items, int *item_codes, int *quantities) {
    float total_bill = 0.0;

    for (int i = 0; i < num_items; i++) {
        total_bill += menu_prices[item_codes[i]] * quantities[i];
    }

    return total_bill;
}

// Print the bill
void print_bill(float total_bill) {
    printf("Your total bill is: $%.2f\n", total_bill);
}

// Main function
int main() {
    int num_items;
    int item_codes[10];
    int quantities[10];

    // Get the user's order
    get_order(&num_items, item_codes, quantities);

    // Calculate the total bill
    float total_bill = calculate_bill(num_items, item_codes, quantities);

    // Print the bill
    print_bill(total_bill);

    return 0;
}