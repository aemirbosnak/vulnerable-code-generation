//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    int choice, item_no, quantity;
    float total_price = 0.0f;
    char customer_name[20];

    printf("Welcome to the Cozy Coffee Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothies\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Please enter the quantity of coffee: ");
            scanf("%d", &quantity);
            total_price += quantity * 50.0f;
            break;
        case 2:
            printf("Please enter the quantity of tea: ");
            scanf("%d", &quantity);
            total_price += quantity * 30.0f;
            break;
        case 3:
            printf("Please enter the quantity of juice: ");
            scanf("%d", &quantity);
            total_price += quantity * 20.0f;
            break;
        case 4:
            printf("Please enter the quantity of smoothies: ");
            scanf("%d", &quantity);
            total_price += quantity * 40.0f;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    printf("Thank you for your order, %s. Your total price is: $%.2f\n", customer_name, total_price);
    printf("Please enjoy your coffee! We hope you have a pleasant time at the Cozy Coffee Cafe!\n");

    system("pause");
}