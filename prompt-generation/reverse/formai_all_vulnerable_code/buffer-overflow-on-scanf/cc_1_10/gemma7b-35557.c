//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Futuristic Cafe Billing System

    // Define a structure to store customer information
    typedef struct Customer
    {
        char name[50];
        char address[100];
        char phone[20];
    } Customer;

    // Create a customer structure
    Customer customer;

    // Get customer information
    printf("Enter your name: ");
    scanf("%s", customer.name);

    printf("Enter your address: ");
    scanf("%s", customer.address);

    printf("Enter your phone number: ");
    scanf("%s", customer.phone);

    // Define a menu of items
    int menu[] = {10, 20, 30, 40, 50};

    // Define item prices
    float prices[] = {2.50, 3.00, 3.50, 4.00, 4.50};

    // Get the customer's order
    int order = -1;
    while (order < 0 || order >= 5)
    {
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &order);
    }

    // Calculate the total cost of the order
    float total_cost = prices[order] * menu[order];

    // Print the customer's order and total cost
    printf("Your order: Item %d - %f\n", menu[order], prices[order]);
    printf("Total cost: %f\n", total_cost);

    // Calculate the tax
    float tax = total_cost * 0.10;

    // Print the tax and total amount due
    printf("Tax: %f\n", tax);
    printf("Total amount due: %f\n", total_cost + tax);

    // Process payment
    printf("Please pay the total amount due: ");
    float payment = 0;
    scanf("%f", &payment);

    // Check if the payment is sufficient
    if (payment < total_cost + tax)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Payment received. Thank you, %s.\n", customer.name);
    }
}