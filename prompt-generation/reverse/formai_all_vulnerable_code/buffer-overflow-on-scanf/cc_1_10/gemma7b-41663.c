//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("CLS");
    printf("------------------------------------------------------------\n");
    printf("           WELCOME TO THE COFFEE HOUSE OF DREAMS           \n");
    printf("------------------------------------------------------------\n");

    int choice, quantity;
    float total = 0.0f;

    printf("Please select a beverage:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothies\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Please enter the quantity of coffee:\n");
            scanf("%d", &quantity);
            total += quantity * 5.0f;
            break;
        case 2:
            printf("Please enter the quantity of tea:\n");
            scanf("%d", &quantity);
            total += quantity * 3.0f;
            break;
        case 3:
            printf("Please enter the quantity of juice:\n");
            scanf("%d", &quantity);
            total += quantity * 4.0f;
            break;
        case 4:
            printf("Please enter the quantity of smoothies:\n");
            scanf("%d", &quantity);
            total += quantity * 6.0f;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Total: $%.2f\n", total);
    printf("Thank you for visiting the Coffee House of Dreams!\n");
    printf("Please come again soon!\n");

    system("PAUSE");
}