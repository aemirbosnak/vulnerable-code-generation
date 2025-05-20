//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char item_name[20];
    int item_quantity;
    float item_price;
    float total_amount = 0.0f;

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

        // Calculate item total cost
        float item_total_cost = item_quantity * item_price;

        // Add item total cost to total amount
        total_amount += item_total_cost;

        // Print item details
        printf("Item name: %s\n", item_name);
        printf("Item quantity: %d\n", item_quantity);
        printf("Item price: %.2f\n", item_price);
        printf("Item total cost: %.2f\n", item_total_cost);
    }

    // Calculate total amount
    float tax_amount = total_amount * 0.1f;
    float grand_total = total_amount + tax_amount;

    // Print invoice
    printf("-------------------------------------------------------------------\n");
    printf("C Cafe Invoice\n");
    printf("-------------------------------------------------------------------\n");
    printf("Items:\n");

    // Loop to print items
    for (int i = 0; i < item_quantity; i++)
    {
        printf("%s\n", item_name);
    }

    printf("\nTotal amount: %.2f\n", total_amount);
    printf("Tax amount: %.2f\n", tax_amount);
    printf("Grand total: %.2f\n", grand_total);

    // Payment
    printf("Enter payment: ");
    float payment = 0.0f;

    // Calculate change
    float change = payment - grand_total;

    // Print change
    printf("Change: %.2f\n", change);

    return 0;
}