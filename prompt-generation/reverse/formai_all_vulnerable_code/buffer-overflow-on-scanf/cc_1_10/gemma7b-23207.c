//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");
    printf("---------------------------------------------------------------------\n");
    printf("                                    CYBERPUNK CAFE\n");
    printf("---------------------------------------------------------------------\n");

    int choice, item_no, qty;
    float total_price = 0.0f;

    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the quantity of coffee:** ");
            scanf("%d", &qty);
            total_price += qty * 2.50f;
            break;
        case 2:
            printf("Enter the quantity of tea:** ");
            scanf("%d", &qty);
            total_price += qty * 2.20f;
            break;
        case 3:
            printf("Enter the quantity of juice:** ");
            scanf("%d", &qty);
            total_price += qty * 2.00f;
            break;
        case 4:
            printf("Enter the quantity of smoothie:** ");
            scanf("%d", &qty);
            total_price += qty * 2.75f;
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("Total price: $%.2f\n", total_price);

    printf("Please insert your payment:\n");
    float payment;
    scanf("%f", &payment);

    if (payment >= total_price)
    {
        printf("Change: $%.2f\n", payment - total_price);
    }
    else
    {
        printf("Insufficient payment.\n");
    }

    printf("Thank you for your visit!\n");
    system("pause");
}