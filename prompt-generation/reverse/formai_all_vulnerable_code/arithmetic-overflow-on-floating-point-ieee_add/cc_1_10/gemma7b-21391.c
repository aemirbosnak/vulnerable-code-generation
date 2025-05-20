//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    int item_no;
    char item_name[20];
    float item_price;
    int quantity;
    float total_amount = 0.0f;
    char customer_name[20];

    // Get customer name
    printf("Enter customer name: ");
    scanf("%s", customer_name);

    // Loop to get item details
    while (1)
    {
        // Get item number, name, and price
        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Get item quantity
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate item total amount
        float item_total = item_price * quantity;

        // Add item total amount to total amount
        total_amount += item_total;

        // Check if customer wants to continue
        char continue_yn;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_yn);

        // Break out of loop if customer does not want to continue
        if (continue_yn == 'N')
            break;
    }

    // Calculate total tax and total amount due
    float total_tax = total_amount * 0.1f;
    float total_amount_due = total_amount + total_tax;

    // Print bill
    printf("--------------------------------------------------------\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Total Items: %d\n", quantity);
    printf("Total Amount: %.2f\n", total_amount);
    printf("Total Tax: %.2f\n", total_tax);
    printf("Total Amount Due: %.2f\n", total_amount_due);
    printf("--------------------------------------------------------\n");

    // Exit program
    return 0;
}