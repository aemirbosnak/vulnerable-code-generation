//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>

// Define constants for menu items
#define COFFEE 1
#define TEA 2
#define SMOOTHIE 3

// Declare global variables
int subtotal = 0;
int tax = 0;
int total = 0;

// Define function to calculate taxes
int calculateTax(int subtotal) {
    return subtotal * 0.05;
}

int main() {
    int choice;
    int quantity;
    int itemPrice;

    // Welcome message
    printf("Welcome to the C Cafe!\n");

    // Display menu options
    printf("MENU\n");
    printf("1. Coffee - $2.00\n");
    printf("2. Tea - $1.50\n");
    printf("3. Smoothie - $3.00\n");

    // Begin ordering process
    do {
        // Get customer's choice of menu item
        printf("Enter your choice (1-3) or 0 to finish:");
        scanf("%d", &choice);

        // Check if customer is finished ordering
        if (choice == 0) {
            break;
        }

        // Get quantity of items ordered
        printf("Enter quantity:");
        scanf("%d", &quantity);

        // Calculate item price and update subtotal
        switch (choice) {
            case COFFEE:
                itemPrice = 200;
                subtotal += itemPrice * quantity;
                break;
            case TEA:
                itemPrice = 150;
                subtotal += itemPrice * quantity;
                break;
            case SMOOTHIE:
                itemPrice = 300;
                subtotal += itemPrice * quantity;
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    // Calculate tax and total
    tax = calculateTax(subtotal);
    total = subtotal + tax;

    // Display receipt
    printf("Order Receipt\n");
    printf("Subtotal: $%d.%02d\n", subtotal / 100, subtotal % 100);
    printf("Tax: $%d.%02d\n", tax / 100, tax % 100);
    printf("Total: $%d.%02d\n", total / 100, total % 100);

    return 0;
}