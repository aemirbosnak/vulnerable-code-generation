//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
/* This program calculates the total cost of a grocery bill with discounts included. */

#include <stdio.h>

/* Define constants for discount rates */
#define DISCOUNT_1 0.1
#define DISCOUNT_2 0.15
#define DISCOUNT_3 0.2

/* Define constants for the minimum amounts needed to receive a discount */
#define MIN_AMOUNT_1 500
#define MIN_AMOUNT_2 1000
#define MIN_AMOUNT_3 1500

/* Calculate discount percentage based on the amount spent */
float calculate_discount(float amount_spent)
{
    if (amount_spent >= MIN_AMOUNT_3) {
        return DISCOUNT_3;
    } else if (amount_spent >= MIN_AMOUNT_2) {
        return DISCOUNT_2;
    } else if (amount_spent >= MIN_AMOUNT_1) {
        return DISCOUNT_1;
    } else {
        return 0.0;
    }
}

int main()
{
    int num_items;
    float item_price, amount_spent;
    float discount_rate, discount_amount, total_cost;

    /* Prompt user to enter number of items */
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    /* Loop through each item and calculate the total amount spent */
    for (int i = 1; i <= num_items; i++) {
        printf("Enter the price of item %d: ", i);
        scanf("%f", &item_price);
        amount_spent += item_price;
    }

    /* Calculate discount rate and amount */
    discount_rate = calculate_discount(amount_spent);
    discount_amount = amount_spent * discount_rate;

    /* Calculate total cost with discount applied */
    total_cost = amount_spent - discount_amount;

    /* Output the results */
    printf("You spent $%.2f on your grocery bill\n", amount_spent);
    printf("Your discount rate is %.0f%%\n", discount_rate * 100);
    printf("You saved $%.2f with your discount\n", discount_amount);
    printf("Your total cost is $%.2f\n", total_cost);

    return 0;
}