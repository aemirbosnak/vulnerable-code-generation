//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Declare variables
    int item_no;
    char item_name[50];
    int quantity;
    float price;
    float total_amount = 0.0f;

    // Create a menu of items
    printf("*** The Last Cafe Menu ***\n");
    printf("1. Coffee - $5.00\n");
    printf("2. Tea - $3.00\n");
    printf("3. Juice - $2.00\n");
    printf("4. Soda - $4.00\n");
    printf("5. Water - $1.00\n");

    // Get the item number, item name, quantity, and price from the user
    printf("Please enter the item number: ");
    scanf("%d", &item_no);

    printf("Please enter the item name: ");
    scanf("%s", item_name);

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    printf("Please enter the price: ");
    scanf("%f", &price);

    // Calculate the total amount
    total_amount = quantity * price;

    // Display the order summary
    printf("\nYour order summary:\n");
    printf("Item number: %d\n", item_no);
    printf("Item name: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Price: $%.2f\n", price);
    printf("Total amount: $%.2f\n", total_amount);

    // Prompt the user to pay
    printf("Please pay the total amount: ");
    float payment;
    scanf("%f", &payment);

    // Calculate the change
    float change = payment - total_amount;

    // Display the change
    printf("\nYour change: $%.2f\n", change);

    // Thank the customer
    printf("Thank you for your business! Come again soon!\n");

    return;
}