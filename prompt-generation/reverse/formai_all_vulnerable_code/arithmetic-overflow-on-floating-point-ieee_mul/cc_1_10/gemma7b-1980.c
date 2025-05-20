//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char customer_name[20];
    char item_name[50];
    int item_quantity;
    float item_price;
    float total_amount = 0.0f;

    // Welcome message
    printf("Welcome to the futuristic C Cafe Billing System!\n");

    // Get customer name
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    // Loop to get item information
    while (1)
    {
        // Get item name
        printf("Enter item name: ");
        scanf("%s", item_name);

        // Check if item name is valid
        if (strcmp(item_name, "Exit") == 0)
        {
            break;
        }

        // Get item quantity
        printf("Enter item quantity: ");
        scanf("%d", &item_quantity);

        // Get item price
        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Calculate item total cost
        float item_total_cost = item_quantity * item_price;

        // Add item total cost to total amount
        total_amount += item_total_cost;

        // Print item details
        printf("Item name: %s\n", item_name);
        printf("Quantity: %d\n", item_quantity);
        printf("Price: %.2f\n", item_price);
        printf("Total cost: %.2f\n", item_total_cost);
    }

    // Calculate total amount due
    float total_due = total_amount * 1.1f;

    // Print billing details
    printf("\nCustomer name: %s\n", customer_name);
    printf("Total amount: %.2f\n", total_amount);
    printf("Total due: %.2f\n", total_due);

    // Thank you message
    printf("Thank you for your visit, %s! See you next time!\n", customer_name);

    return 0;
}