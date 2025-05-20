//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no;
    char item_name[20];
    int quantity;
    float price;
    float total_amount = 0.0f;

    // Display menu
    printf("Welcome to the Cool Coffee Cafe!\n\n");
    printf("Please select an item: \n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");

    // Get item number
    scanf("%d", &item_no);

    // Get item name
    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Coffee");
            break;
        case 2:
            strcpy(item_name, "Tea");
            break;
        case 3:
            strcpy(item_name, "Juice");
            break;
        case 4:
            strcpy(item_name, "Smoothie");
            break;
        default:
            printf("Invalid item number.\n");
            return;
    }

    // Get quantity
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Get price
    switch (item_no)
    {
        case 1:
            price = 5.0f;
            break;
        case 2:
            price = 3.0f;
            break;
        case 3:
            price = 4.0f;
            break;
        case 4:
            price = 6.0f;
            break;
        default:
            printf("Invalid item number.\n");
            return;
    }

    // Calculate total amount
    total_amount = quantity * price;

    // Display bill
    printf("\nYour order:\n");
    printf("%s (%d) - %f\n", item_name, quantity, price);
    printf("Total amount: %f\n", total_amount);

    // Collect payment
    printf("Please insert money: ");
    float payment;
    scanf("%f", &payment);

    // Calculate change
    float change = payment - total_amount;

    // Return change
    printf("Your change: %f\n", change);

    return;
}