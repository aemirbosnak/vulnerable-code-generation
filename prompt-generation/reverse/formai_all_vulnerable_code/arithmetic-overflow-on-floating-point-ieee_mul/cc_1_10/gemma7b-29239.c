//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char item_name[20];
    int item_quantity;
    float item_price;
    float total_amount = 0.0f;

    // Loop to add items to the bill
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        if (strcmp(item_name, "q") == 0)
        {
            break;
        }

        printf("Enter item quantity: ");
        scanf("%d", &item_quantity);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Calculate item total
        float item_total = item_quantity * item_price;

        // Add item total to the total amount
        total_amount += item_total;

        // Print item details
        printf("Item name: %s\n", item_name);
        printf("Item quantity: %d\n", item_quantity);
        printf("Item price: %.2f\n", item_price);
        printf("Item total: %.2f\n", item_total);
        printf("\n");
    }

    // Print total amount
    printf("Total amount: %.2f\n", total_amount);

    // Calculate tax
    float tax = total_amount * 0.1f;

    // Print tax
    printf("Tax: %.2f\n", tax);

    // Calculate total cost
    float total_cost = total_amount + tax;

    // Print total cost
    printf("Total cost: %.2f\n", total_cost);

    return 0;
}