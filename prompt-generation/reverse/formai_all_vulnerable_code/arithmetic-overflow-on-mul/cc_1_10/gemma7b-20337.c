//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>

void main()
{
    int choice, quantity, item_no;
    float total_price = 0.0;

    // Display menu
    printf("Welcome to the C Cafe!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Water\n");

    // Get user input
    scanf("Enter your choice:", &choice);

    // Calculate item cost based on choice
    switch (choice)
    {
        case 1:
            item_no = 1;
            quantity = 0;
            break;
        case 2:
            item_no = 2;
            quantity = 0;
            break;
        case 3:
            item_no = 3;
            quantity = 0;
            break;
        case 4:
            item_no = 4;
            quantity = 0;
            break;
        default:
            printf("Invalid selection.\n");
            return;
    }

    // Get item quantity
    printf("Enter the quantity of items: ");
    scanf("%d", &quantity);

    // Calculate total price
    total_price = quantity * item_no * 2.0;

    // Display total price
    printf("Your total price is: $%.2f", total_price);

    // Thank you
    printf("\nThank you for your visit to the C Cafe!\n");

    return;
}