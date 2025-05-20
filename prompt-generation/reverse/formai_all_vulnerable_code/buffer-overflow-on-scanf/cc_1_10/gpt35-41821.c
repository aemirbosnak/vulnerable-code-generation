//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void menu(int *quantity1, int *quantity2);
void pricing(int quantity1, int quantity2, double *price1, double *price2);
double calculate_total(double price1, double price2);
void print_receipt(int quantity1, int quantity2, double price1, double price2, double total);

int main() {
    int quantity1 = 0, quantity2 = 0;
    double price1 = 0, price2 = 0, total = 0;

    // Welcome message
    printf("Welcome to C Cafe Billing System!\n\n");

    // Display menu and get user input
    menu(&quantity1, &quantity2);
    
    // Calculate pricing and total
    pricing(quantity1, quantity2, &price1, &price2);
    total = calculate_total(price1, price2);
    
    // Print receipt
    print_receipt(quantity1, quantity2, price1, price2, total);

    return 0;
}

// Function to display menu and get user input
void menu(int *quantity1, int *quantity2) {
    printf("Menu:\n");
    printf("1. Coffee - $2.00\n");
    printf("2. Croissant - $1.50\n\n");

    // Get user input for quantity of coffee
    printf("Enter quantity for coffee: ");
    scanf("%d", quantity1);

    // Get user input for quantity of croissant
    printf("Enter quantity for croissant: ");
    scanf("%d", quantity2);
}

// Function to calculate pricing
void pricing(int quantity1, int quantity2, double *price1, double *price2) {
    double coffee_price = 2.00, croissant_price = 1.50;

    // Calculate price for coffee
    *price1 = quantity1 * coffee_price;

    // Calculate price for croissant
    *price2 = quantity2 * croissant_price;
}

// Function to calculate total
double calculate_total(double price1, double price2) {
    double tax_rate = 0.07, total = 0;

    // Calculate total price with tax
    total = (price1 + price2) * (1 + tax_rate);

    return total;
}

// Function to print receipt
void print_receipt(int quantity1, int quantity2, double price1, double price2, double total) {
    printf("\nReceipt:\n");
    printf("%d x Coffee: $%.2f\n", quantity1, price1);
    printf("%d x Croissant: $%.2f\n", quantity2, price2);
    printf("Total Price (with tax): $%.2f\n", total);
    printf("Thank you for dining at C Cafe!");
}