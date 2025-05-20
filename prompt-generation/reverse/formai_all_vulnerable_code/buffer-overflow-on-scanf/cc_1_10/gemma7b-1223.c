//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no, qty, i, total_items = 0;
    float price, total_amount = 0.0f;
    char name[20];

    // Display menu
    printf("\nWelcome to the Coffee Shop!\n");
    printf("Please select an item from the menu:\n");
    printf("1. Coffee\t\tPrice: $2.00\n");
    printf("2. Tea\t\tPrice: $1.50\n");
    printf("3. Juice\t\tPrice: $1.00\n");
    printf("4. Smoothie\t\tPrice: $1.25\n");

    // Get customer name and item number
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter item number: ");
    scanf("%d", &item_no);

    // Calculate item quantity
    printf("Enter quantity: ");
    scanf("%d", &qty);

    // Calculate total items and price
    total_items++;
    switch (item_no)
    {
        case 1:
            price = 2.00f;
            break;
        case 2:
            price = 1.50f;
            break;
        case 3:
            price = 1.00f;
            break;
        case 4:
            price = 1.25f;
            break;
    }
    total_amount = price * qty;

    // Print invoice
    printf("\nInvoice\n");
    printf("Customer Name: %s\n", name);
    printf("Item No.: %d\n", item_no);
    printf("Item Name: Coffee\n", item_no);
    printf("Quantity: %d\n", qty);
    printf("Price: $%.2f\n", price);
    printf("Total Amount: $%.2f\n", total_amount);

    // Calculate tax and total amount
    float tax = 0.08f;
    float total_tax = total_amount * tax;
    float total_payable = total_amount + total_tax;

    // Print tax and total amount
    printf("Tax: $%.2f\n", tax);
    printf("Total Tax: $%.2f\n", total_tax);
    printf("Total Payable: $%.2f\n", total_payable);

    // Thank you message
    printf("\nThank you for your order, %s. We hope you enjoy your coffee!\n", name);

    return;
}