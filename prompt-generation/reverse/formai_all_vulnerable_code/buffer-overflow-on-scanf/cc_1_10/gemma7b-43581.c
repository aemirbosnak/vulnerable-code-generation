//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

int main()
{
    // Declare variables
    char name[20];
    int item_no, quantity, i, total_items = 0, total_amount = 0;
    float price, tax, discount, final_amount;

    // Print welcome message
    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to get customer information and order items
    while (1)
    {
        // Get customer name
        printf("Enter your name: ");
        scanf("%s", name);

        // Get item number, quantity, and price
        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter item price: ");
        scanf("%f", &price);

        // Calculate item total amount
        float item_total = quantity * price;

        // Update total items and total amount
        total_items++;
        total_amount += item_total;

        // Check if customer wants to continue or exit
        printf("Do you want to continue ordering (Y/N)? ");
        char answer;
        scanf("%c", &answer);

        if (answer == 'N')
            break;
    }

    // Calculate tax, discount, and final amount
    tax = total_amount * PI / 100;
    discount = total_amount * 10 / 100;
    final_amount = total_amount + tax - discount;

    // Print invoice
    printf("---------------------------------------------------\n");
    printf("Customer Name: %s\n", name);
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: %.2f\n", total_amount);
    printf("Tax: %.2f\n", tax);
    printf("Discount: %.2f\n", discount);
    printf("Final Amount: %.2f\n", final_amount);
    printf("---------------------------------------------------\n");

    // Thank customer and exit
    printf("Thank you for visiting the C Cafe! See you next time!\n");
    return 0;
}