//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    // Define variables
    char name[20];
    int quantity, item_no, total_items = 0, item_price[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float total_amount = 0.0f;

    // Get customer name
    printf("Enter your name: ");
    scanf("%s", name);

    // Loop to get items
    while (1)
    {
        // Get item number and quantity
        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if item is valid
        if (item_no < 1 || item_no > 10)
        {
            printf("Invalid item number.\n");
            continue;
        }

        // Calculate item total cost
        int item_total_cost = item_price[item_no - 1] * quantity;

        // Add item to total items and amount
        total_items++;
        total_amount += (float)item_total_cost;

        // Ask if customer wants to continue
        char continue_yn;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_yn);

        // Break out of loop if customer does not want to continue
        if (continue_yn == 'N' || continue_yn == 'n')
            break;
    }

    // Calculate total amount due
    float total_due = total_amount * 1.1f;

    // Print invoice
    printf("\n**Invoice**\n");
    printf("Customer name: %s\n", name);
    printf("Total items: %d\n", total_items);
    printf("Total amount: %.2f\n", total_amount);
    printf("Total due: %.2f\n", total_due);

    // Prompt customer to pay
    printf("Please pay the total amount: ");
    float payment;
    scanf("%f", &payment);

    // Check if payment is sufficient
    if (payment < total_due)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Thank you for your payment.\n");
    }

    return 0;
}