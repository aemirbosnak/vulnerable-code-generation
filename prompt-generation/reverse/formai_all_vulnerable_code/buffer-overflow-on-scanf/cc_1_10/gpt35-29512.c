//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define constant prices for menu items
#define COFFEE_PRICE 2.50
#define TEA_PRICE 2.00
#define MUFFIN_PRICE 1.75
#define BAGEL_PRICE 1.50
#define TAX_RATE 0.06

int main() {

    // Variables for menu item quantities
    int coffee_qty, tea_qty, muffin_qty, bagel_qty;

    printf("Welcome to the C Cafe! \n");

    // Ask the user for quantity of each menu item
    printf("How many coffees would you like? ");
    scanf("%d", &coffee_qty);

    printf("How many teas would you like? ");
    scanf("%d", &tea_qty);

    printf("How many muffins would you like? ");
    scanf("%d", &muffin_qty);

    printf("How many bagels would you like? ");
    scanf("%d", &bagel_qty);

    // Calculate subtotal and tax
    double subtotal = (coffee_qty * COFFEE_PRICE) + (tea_qty * TEA_PRICE) + (muffin_qty * MUFFIN_PRICE) + (bagel_qty * BAGEL_PRICE);
    double tax = subtotal * TAX_RATE;

    // Calculate total
    double total = subtotal + tax;

    // Print the bill
    printf("\nHere is your bill: \n");
    printf("-------------------\n");
    printf("%d coffee(s) \t\t\t $%.2lf\n", coffee_qty, coffee_qty * COFFEE_PRICE);
    printf("%d tea(s) \t\t\t $%.2lf\n", tea_qty, tea_qty * TEA_PRICE);
    printf("%d muffin(s) \t\t\t $%.2lf\n", muffin_qty, muffin_qty * MUFFIN_PRICE);
    printf("%d bagel(s) \t\t\t $%.2lf\n", bagel_qty, bagel_qty * BAGEL_PRICE);
    printf("-------------------\n");
    printf("Subtotal \t\t\t $%.2lf\n", subtotal);
    printf("Tax \t\t\t\t $%.2lf\n", tax);
    printf("TOTAL \t\t\t\t $%.2lf\n", total);

    return 0;
}