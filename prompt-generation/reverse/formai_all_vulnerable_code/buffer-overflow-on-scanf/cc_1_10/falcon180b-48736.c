//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the prices of items on the menu
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.75
#define PASTRY_PRICE 3.00

// Define the tax rate as a decimal
#define TAX_RATE 0.08

// Define the maximum number of items a customer can order
#define MAX_ITEMS 10

int main() {
    int numItems;
    double subtotal, tax, total;

    // Get the number of items ordered from the user
    printf("How many items would you like to order? ");
    scanf("%d", &numItems);

    // Initialize the subtotal to zero
    subtotal = 0.0;

    // Loop through each item and add its price to the subtotal
    for (int i = 0; i < numItems; i++) {
        printf("Enter the item number (1 for coffee, 2 for tea, 3 for pastry): ");
        int itemNum;
        scanf("%d", &itemNum);

        switch (itemNum) {
            case 1:
                subtotal += COFFEE_PRICE;
                break;
            case 2:
                subtotal += TEA_PRICE;
                break;
            case 3:
                subtotal += PASTRY_PRICE;
                break;
            default:
                printf("Invalid item number.\n");
                return 1;
        }
    }

    // Calculate the tax and total
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    // Print the subtotal, tax, and total
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    return 0;
}