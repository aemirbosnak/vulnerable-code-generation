//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, item_no, quantity, total_amount = 0;
    char item_name[20];

    // Display the menu
    printf("\tWelcome to the Coffee Cafe!\n");
    printf("------------------------\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Biscuit\n");
    printf("Enter your choice:");

    // Get the user's choice
    scanf("%d", &choice);

    // Switch case to handle the user's choice
    switch (choice)
    {
        case 1:
            printf("Enter the item name:");
            scanf("%s", item_name);
            printf("Enter the quantity:");
            scanf("%d", &quantity);
            total_amount += quantity * 50;
            break;
        case 2:
            printf("Enter the item name:");
            scanf("%s", item_name);
            printf("Enter the quantity:");
            scanf("%d", &quantity);
            total_amount += quantity * 40;
            break;
        case 3:
            printf("Enter the item name:");
            scanf("%s", item_name);
            printf("Enter the quantity:");
            scanf("%d", &quantity);
            total_amount += quantity * 30;
            break;
        case 4:
            printf("Enter the item name:");
            scanf("%s", item_name);
            printf("Enter the quantity:");
            scanf("%d", &quantity);
            total_amount += quantity * 20;
            break;
        default:
            printf("Invalid choice.\n");
    }

    // Display the total amount
    printf("\nTotal amount: $%d\n", total_amount);

    // Prompt for payment
    printf("Please pay the amount.\n");

    // Get the payment
    int payment;
    scanf("%d", &payment);

    // Check if the payment is sufficient
    if (payment < total_amount)
    {
        printf("Insufficient payment.\n");
    }
    else
    {
        printf("Thank you for your payment.\n");
    }
}