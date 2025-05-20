//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, item_no, quantity, total_items = 0;
    float price, total_amount = 0.0, item_price;
    char name[20];

    // Create a loop to get the customer's name, item number, quantity, and price
    while (1)
    {
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Calculate the total cost of the item
        total_items++;
        price = quantity * item_price;
        total_amount += price;

        // Check if the customer wants to continue shopping
        printf("Do you want to continue shopping? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
            break;
    }

    // Calculate the total cost of the order
    total_amount = total_amount + total_items * 2.00;

    // Print the customer's invoice
    printf("\n-------------------------------------------------------------------\n");
    printf("Customer Name: %s\n", name);
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("-------------------------------------------------------------------\n");

    // Prompt the customer to pay
    printf("Please pay the total amount: ");
    float payment;
    scanf("%f", &payment);

    // Check if the customer has paid enough
    if (payment < total_amount)
    {
        printf("You have not paid enough. Please pay the remaining amount: ");
        payment = payment - total_amount;
        scanf("%f", &payment);
    }

    // Print the receipt
    printf("\n-------------------------------------------------------------------\n");
    printf("Thank you for your purchase, %s!\n", name);
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("Payment: $%.2f\n", payment);
    printf("Change: $%.2f\n", payment - total_amount);
    printf("-------------------------------------------------------------------\n");

    // Exit the program
    exit(0);
}