//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char item_name[50];
    int item_quantity, item_price;
    float total_amount, tax_amount, grand_total;

    // Initialize variables
    total_amount = 0;
    tax_amount = 0;
    grand_total = 0;

    // Loop until the customer enters "q"
    while (strcmp(item_name, "q") != 0)
    {
        // Get the item name, quantity, and price
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item quantity: ");
        scanf("%d", &item_quantity);

        printf("Enter item price: ");
        scanf("%d", &item_price);

        // Calculate the item total cost
        int item_total_cost = item_quantity * item_price;

        // Add the item total cost to the total amount
        total_amount += item_total_cost;

        // Calculate the tax amount
        tax_amount = total_amount * 0.1;

        // Calculate the grand total
        grand_total = total_amount + tax_amount;

        // Print the item details
        printf("Item name: %s\n", item_name);
        printf("Item quantity: %d\n", item_quantity);
        printf("Item price: %d\n", item_price);
        printf("Item total cost: %d\n", item_total_cost);

        // Print the total amount
        printf("Total amount: %.2f\n", total_amount);

        // Print the tax amount
        printf("Tax amount: %.2f\n", tax_amount);

        // Print the grand total
        printf("Grand total: %.2f\n", grand_total);

        // Clear the buffer
        scanf("\n");
    }

    // Print the final bill
    printf("Thank you for your order. Your total bill is: $%.2f", grand_total);

    // Exit the program
    exit(0);
}