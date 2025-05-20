//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char item_name[20];
    int quantity;
    float price;
    float total_price = 0.0;
    char choice;

    printf("Welcome to the Coffee Shop!\n");

    // Loop until the customer enters 'q'
    while (choice != 'q')
    {
        printf("Enter the name of the item: ");
        scanf("%s", item_name);

        printf("Enter the quantity: ");
        scanf("%d", &quantity);

        printf("Enter the price of the item: ");
        scanf("%f", &price);

        total_price += quantity * price;

        printf("Do you want to continue ordering? (y/n): ");
        scanf(" %c", &choice);
    }

    // Print the total price
    printf("Total price: $%.2f", total_price);

    // Calculate the tax
    float tax = total_price * 0.08;

    // Print the tax
    printf("Tax: $%.2f", tax);

    // Calculate the total amount due
    float total_amount_due = total_price + tax;

    // Print the total amount due
    printf("Total amount due: $%.2f", total_amount_due);

    // Prompt the customer to pay
    printf("Please pay the total amount due: ");

    // Get the customer's payment
    float payment;

    scanf("%f", &payment);

    // Check if the payment is sufficient
    if (payment < total_amount_due)
    {
        printf("Sorry, your payment is not sufficient.\n");
    }
    else
    {
        printf("Thank you for your payment.\n");
    }
}