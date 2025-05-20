//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our Cafe's Delectable Menu
char menu[10][50] = {
    "Espresso",
    "Americano",
    "Cappuccino",
    "Latte",
    "Mocha",
    "Caramel Macchiato",
    "Iced Coffee",
    "Tea",
    "Hot Chocolate",
    "Pastry"
};

double prices[10] = {
    2.50,
    3.50,
    3.75,
    4.00,
    4.50,
    4.75,
    3.00,
    2.00,
    2.50,
    1.50
};

// Main Course: The Billing Odyssey
void bill() {
    int choice, quantity;
    double total = 0.0;

    // Welcome our patrons with open arms
    printf("Welcome to our Humble Cafe!\n");

    // Display the tantalizing menu
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }

    // Ask for their delectable choices
    printf("\nEnter your choice (1-10): ");
    scanf("%d", &choice);

    // Validate their choice
    while (choice < 1 || choice > 10) {
        printf("Invalid choice! Please enter a number from 1-10: ");
        scanf("%d", &choice);
    }

    // Request the quantity of their desire
    printf("How many would you like? ");
    scanf("%d", &quantity);

    // Calculate the subtotal
    total = prices[choice - 1] * quantity;

    // Print the subtotal with a flourish
    printf("Subtotal: $%.2f\n", total);

    // Apply a generous 10% discount for our loyal customers
    total *= 0.9;

    // Grand finale: Display the total bill
    printf("Total Bill: $%.2f\n", total);

    // Express our gratitude
    printf("Thank you for dining with us! Enjoy your refreshments!\n");
}

// Orchestrate the symphony of flavors
int main() {
    int option;

    // Keep the billing party going until they've had their fill
    do {
        printf("----------------------------------\n");
        printf("1. Place an Order\n");
        printf("2. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                bill();
                break;
            case 2:
                printf("Thank you for visiting our Cafe! Until next time!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
        }
    } while (option != 2);

    return 0;
}