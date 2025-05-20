//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no, qty, total_items = 0, total_amount = 0;
    char item_name[20];
    float price;

    // Display welcome message
    printf("Welcome to the Coffee Shop!\n");

    // Loop to get items
    while (1)
    {
        // Get item name, number, and price
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter item quantity: ");
        scanf("%d", &qty);

        // Calculate item cost
        price = 0.0;
        switch (item_no)
        {
            case 1:
                price = 50.0;
                break;
            case 2:
                price = 60.0;
                break;
            case 3:
                price = 70.0;
                break;
            case 4:
                price = 80.0;
                break;
            case 5:
                price = 90.0;
                break;
            default:
                printf("Invalid item number.\n");
                break;
        }

        // Calculate total cost
        total_amount += qty * price;
        total_items++;

        // Check if the customer wants to continue or quit
        char continue_or_quit;
        printf("Do you want to continue (Y/N)? ");
        scanf(" %c", &continue_or_quit);

        // If the customer wants to quit, break out of the loop
        if (continue_or_quit == 'N')
            break;
    }

    // Calculate total cost
    total_amount = total_amount * 1.1;

    // Display total items and amount
    printf("Total items: %d\n", total_items);
    printf("Total amount: $%.2f\n", total_amount);

    // Prompt for payment
    printf("Please pay the total amount: ");
    int payment;
    scanf("%d", &payment);

    // Check if the payment is sufficient
    if (payment < total_amount)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Payment received. Thank you for your visit!\n");
    }
}