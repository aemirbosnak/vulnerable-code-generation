//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, item_no, quantity;
    float total_amount = 0.0f;
    char customer_name[20];

    // Display menu
    printf("Welcome to Coffee Cafe!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Snack\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Calculate item price based on choice
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
            printf("Invalid choice.\n");
            return;
    }

    // Get item quantity
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Calculate total amount
    total_amount = quantity * 5.0f;

    // Get customer name
    printf("Enter your name: ");
    scanf("%s", customer_name);

    // Print receipt
    printf("---------------------------------------\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Item No: %d\n", item_no);
    printf("Quantity: %d\n", quantity);
    printf("Total Amount: %.2f\n", total_amount);
    printf("---------------------------------------\n");

    // Thank you message
    printf("Thank you for visiting Coffee Cafe, %s!\n", customer_name);
}