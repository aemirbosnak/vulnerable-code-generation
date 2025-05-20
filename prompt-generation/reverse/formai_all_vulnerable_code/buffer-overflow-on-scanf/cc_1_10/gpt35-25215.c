//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These are predefined prices for the cafe items
#define COFFEE_PRICE 100
#define TEA_PRICE 80
#define COOKIE_PRICE 25
#define SANDWICH_PRICE 150

// This function calculates the total amount to be paid by the customer
int calculate_total(int coffee, int tea, int cookie, int sandwich) {
    int total = (coffee * COFFEE_PRICE) + (tea * TEA_PRICE) + (cookie * COOKIE_PRICE) + (sandwich * SANDWICH_PRICE);
    return total;
}

int main() {
    int coffee = 0;
    int tea = 0;
    int cookie = 0;
    int sandwich = 0;

    // Welcome message for the customer
    printf("Welcome to the Mind-Bending Cafe Billing System!\n");
    printf("Please enter the number of items you want to purchase.\n");

    // Taking input from the customer
    printf("Number of coffees: ");
    scanf("%d", &coffee);

    printf("Number of teas: ");
    scanf("%d", &tea);

    printf("Number of cookies: ");
    scanf("%d", &cookie);

    printf("Number of sandwiches: ");
    scanf("%d", &sandwich);

    int total = calculate_total(coffee, tea, cookie, sandwich);

    // Displaying the invoice to the customer
    printf("\n*********** INVOICE ***********\n");
    printf("Coffee: %d X %d = %d\n", coffee, COFFEE_PRICE, coffee * COFFEE_PRICE);
    printf("Tea: %d X %d = %d\n", tea, TEA_PRICE, tea * TEA_PRICE);
    printf("Cookie: %d X %d = %d\n", cookie, COOKIE_PRICE, cookie * COOKIE_PRICE);
    printf("Sandwich: %d X %d = %d\n", sandwich, SANDWICH_PRICE, sandwich * SANDWICH_PRICE);
    printf("----------------------------------\n");
    printf("TOTAL AMOUNT: %d\n", total);
    printf("----------------------------------\n");
    printf("Thank you for choosing the Mind-Bending Cafe. Please come again!\n");

    return 0;
}