//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    char name[20];
    int item_no;
    float item_price;
    int quantity;
    float total_amount = 0.0f;

    // Loop to get customer information and order items
    while (1)
    {
        // Get customer name
        printf("Enter your name: ");
        scanf("%s", name);

        // Get item number
        printf("Enter item number: ");
        scanf("%d", &item_no);

        // Get item price
        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Get quantity
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate total amount
        float item_total = item_price * quantity;
        total_amount += item_total;

        // Check if customer wants to continue
        char continue_flag;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_flag);

        // If customer does not want to continue, break out of the loop
        if (continue_flag == 'N')
            break;
    }

    // Print receipt
    printf("--------------------------------------------------------\n");
    printf("Customer Name: %s\n", name);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("--------------------------------------------------------\n");

    // Calculate tax and total cost
    float tax = total_amount * 0.08f;
    float total_cost = total_amount + tax;

    // Print tax and total cost
    printf("Tax: $%.2f\n", tax);
    printf("Total Cost: $%.2f\n", total_cost);

    // Thank you message
    printf("Thank you for your order, %s!\n", name);

    return 0;
}