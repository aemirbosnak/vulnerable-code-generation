//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BILL_TOTAL 10

int main()
{
    char bill[BILL_TOTAL][20] = {
        "Cappuccino",
        "Latte",
        "Americano",
        "Mocha",
        "Macchiato",
        "Frappe",
        "Tea",
        "Coffee",
        "Juice",
        "Smoothie"
    };

    int bill_quantity[BILL_TOTAL] = { 0 };
    float bill_price[BILL_TOTAL] = { 3.50, 2.99, 2.25, 3.25, 2.49, 3.99, 1.25, 2.50, 1.50, 2.75 };

    int i, total_amount = 0, total_items = 0;

    printf("Welcome to the Caffeinated Heaven!\n");

    // Get the number of items
    printf("How many items would you like to order? ");
    scanf("%d", &total_items);

    // Iterate over the items
    for (i = 0; i < total_items; i++)
    {
        // Get the item name
        printf("Enter the name of item: ");
        scanf("%s", bill[total_amount]);

        // Get the item quantity
        printf("Enter the quantity: ");
        scanf("%d", &bill_quantity[total_amount]);

        // Calculate the item price
        bill_price[total_amount] = bill_quantity[total_amount] * bill_price[total_amount - 1];

        // Increment the total amount
        total_amount++;
    }

    // Calculate the total amount
    for (i = 0; i < total_amount; i++)
    {
        total_amount += bill_quantity[i] * bill_price[i];
    }

    // Print the bill
    printf("Your bill:\n");
    for (i = 0; i < total_amount; i++)
    {
        printf("%s - %d x %.2f = %.2f\n", bill[i], bill_quantity[i], bill_price[i], bill_quantity[i] * bill_price[i]);
    }

    // Print the total amount
    printf("Total amount: %.2f\n", total_amount);

    // Thank you
    printf("Thank you for your visit to Caffeinated Heaven!\n");

    return 0;
}