//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>

void generate_bill()
{
    system("cls");
    printf("---------------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("---------------------------------------------------------\n");

    // Get the customer name
    char customer_name[20];
    printf("Enter your name: ");
    scanf("%s", customer_name);

    // Get the customer address
    char customer_address[100];
    printf("Enter your address: ");
    scanf("%s", customer_address);

    // Get the customer phone number
    int customer_phone_number;
    printf("Enter your phone number: ");
    scanf("%d", &customer_phone_number);

    // Print the bill
    printf("Customer Name: %s\n", customer_name);
    printf("Customer Address: %s\n", customer_address);
    printf("Customer Phone Number: %d\n", customer_phone_number);

    // Calculate the total cost
    int total_cost = 0;
    printf("Enter the total cost of your order: ");
    scanf("%d", &total_cost);

    // Print the total cost
    printf("Total Cost: %d\n", total_cost);

    // Calculate the tax
    int tax = (total_cost * 10) / 100;

    // Print the tax
    printf("Tax: %d\n", tax);

    // Calculate the total amount due
    int total_amount_due = total_cost + tax;

    // Print the total amount due
    printf("Total Amount Due: %d\n", total_amount_due);

    // Get the payment
    int payment = 0;
    printf("Enter the payment: ");
    scanf("%d", &payment);

    // Calculate the change
    int change = payment - total_amount_due;

    // Print the change
    printf("Change: %d\n", change);

    // Print the thank you message
    printf("Thank you for your visit to C Cafe!\n");

    // Pause the program
    system("pause");
}

int main()
{
    generate_bill();

    return 0;
}