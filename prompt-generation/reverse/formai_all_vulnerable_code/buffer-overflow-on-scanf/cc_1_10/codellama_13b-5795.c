//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
/*
 * C Cafe Billing System
 *
 * This program is an example of a simple cafe billing system.
 * It takes input from the user, calculates the total cost of their order,
 * and then displays the total and the bill.
 */

#include <stdio.h>

int main() {
    // Declare variables
    int choice, quantity;
    float price, total;

    // Welcome message
    printf("Welcome to our cafe!\n");

    // Print menu
    printf("Menu:\n");
    printf("1. Coffee - $1.00\n");
    printf("2. Tea - $0.75\n");
    printf("3. Cappuccino - $2.50\n");
    printf("4. Latte - $3.00\n");
    printf("5. Mocha - $4.00\n");
    printf("6. Espresso - $2.00\n");

    // Get user input
    printf("What would you like to order? (1-6): ");
    scanf("%d", &choice);

    // Calculate price based on user input
    switch (choice) {
    case 1:
        price = 1.00;
        break;
    case 2:
        price = 0.75;
        break;
    case 3:
        price = 2.50;
        break;
    case 4:
        price = 3.00;
        break;
    case 5:
        price = 4.00;
        break;
    case 6:
        price = 2.00;
        break;
    default:
        printf("Invalid choice. Try again.\n");
        return 1;
    }

    // Get quantity
    printf("How many would you like to order? (1-10): ");
    scanf("%d", &quantity);

    // Calculate total
    total = price * quantity;

    // Display bill
    printf("Your bill is: $%.2f\n", total);

    return 0;
}