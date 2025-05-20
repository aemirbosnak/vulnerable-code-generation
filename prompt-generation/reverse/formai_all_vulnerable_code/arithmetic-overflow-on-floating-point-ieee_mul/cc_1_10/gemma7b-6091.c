//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char item_name[20];
    int item_quantity;
    float item_price;
    float total_amount = 0.0f;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop until the customer enters "q"
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

        // Calculate the item total
        float item_total = item_quantity * item_price;

        // Add the item total to the total amount
        total_amount += item_total;

        // Print the item details
        printf("Item name: %s\n", item_name);
        printf("Item quantity: %d\n", item_quantity);
        printf("Item price: %.2f\n", item_price);
        printf("Item total: %.2f\n", item_total);
    }

    // Calculate the total tax
    float total_tax = total_amount * 0.1f;

    // Calculate the total amount due
    float total_due = total_amount + total_tax;

    // Print the bill
    printf("---------------------------------------\n");
    printf("Total amount: %.2f\n", total_amount);
    printf("Total tax: %.2f\n", total_tax);
    printf("Total due: %.2f\n", total_due);
    printf("Thank you for your visit to the C Cafe!\n");

    // Exit the program
    exit(0);
}