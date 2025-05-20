//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    int choice, item_num, quantity;
    float total_price = 0.0f;

    // Display menu
    printf("Welcome to Coffee Haven!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Water\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Calculate item price based on user choice
    switch (choice)
    {
        case 1:
            item_num = 1;
            quantity = 0;
            printf("Enter the quantity of coffee: ");
            scanf("%d", &quantity);
            total_price += quantity * 50.0f;
            break;
        case 2:
            item_num = 2;
            quantity = 0;
            printf("Enter the quantity of tea: ");
            scanf("%d", &quantity);
            total_price += quantity * 40.0f;
            break;
        case 3:
            item_num = 3;
            quantity = 0;
            printf("Enter the quantity of juice: ");
            scanf("%d", &quantity);
            total_price += quantity * 30.0f;
            break;
        case 4:
            item_num = 4;
            quantity = 0;
            printf("Enter the quantity of water: ");
            scanf("%d", &quantity);
            total_price += quantity * 20.0f;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Display total price
    printf("Total price: $%.2f\n", total_price);

    // Calculate tax and add it to the total price
    float tax = total_price * 0.1f;
    total_price += tax;

    // Display final total price
    printf("Final total price: $%.2f\n", total_price);

    // Prompt for payment
    printf("Please provide payment: $");
    float payment = 0.0f;

    // Get user payment
    scanf("%f", &payment);

    // Check if payment is sufficient
    if (payment < total_price)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Thank you for your order, Mr./Ms. Customer!\n");
    }
}