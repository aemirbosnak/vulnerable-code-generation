//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char item_name[20];
    int item_quantity;
    float item_price;
    float total_amount = 0.0;

    // Loop to get items
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        if (strcmp(item_name, "q") == 0)
            break;

        printf("Enter item quantity: ");
        scanf("%d", &item_quantity);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Calculate item total
        float item_total = item_quantity * item_price;

        // Add item total to total amount
        total_amount += item_total;

        // Print item details
        printf("Item name: %s\n", item_name);
        printf("Item quantity: %d\n", item_quantity);
        printf("Item price: %.2f\n", item_price);
        printf("Item total: %.2f\n", item_total);
        printf("\n");
    }

    // Calculate total amount
    float total_tax = total_amount * 0.1;
    float total_bill = total_amount + total_tax;

    // Print total bill
    printf("Total amount: %.2f\n", total_amount);
    printf("Total tax: %.2f\n", total_tax);
    printf("Total bill: %.2f\n", total_bill);

    // Prompt for payment
    printf("Enter payment: ");
    float payment = 0.0;

    // Validate payment
    while (payment < total_bill)
    {
        printf("Payment is insufficient. Please provide more payment: ");
        scanf("%f", &payment);
    }

    // Calculate change
    float change = payment - total_bill;

    // Print change
    printf("Change: %.2f\n", change);

    // Thank you
    printf("Thank you for your purchase!\n");
}