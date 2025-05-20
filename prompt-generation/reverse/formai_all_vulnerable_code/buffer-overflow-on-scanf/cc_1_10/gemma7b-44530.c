//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, quantity, i, total = 0;
    char item[20];

    // Display menu items
    printf("Menu:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothies\n");

    // Get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Calculate quantity
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Get item name
    printf("Enter the item name: ");
    scanf("%s", item);

    // Calculate total cost
    switch (choice)
    {
        case 1:
            total = quantity * 50;
            break;
        case 2:
            total = quantity * 40;
            break;
        case 3:
            total = quantity * 30;
            break;
        case 4:
            total = quantity * 20;
            break;
    }

    // Print receipt
    printf("Receipt:\n");
    printf("Item: %s\n", item);
    printf("Quantity: %d\n", quantity);
    printf("Total cost: %d\n", total);

    // Calculate tax
    int tax = total * 10 / 100;

    // Print tax
    printf("Tax: %d\n", tax);

    // Calculate total amount paid
    int total_amount = total + tax;

    // Print total amount paid
    printf("Total amount paid: %d\n", total_amount);

    return;
}