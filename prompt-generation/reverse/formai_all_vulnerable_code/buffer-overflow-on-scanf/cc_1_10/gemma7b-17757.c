//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    printf("Welcome to the Cozy Coffee Cafe!\n");
    printf("Please select an item from the menu:\n");
    printf("1. Cappuccino\n");
    printf("2. Latte\n");
    printf("3. Mocha\n");
    printf("4. Espresso\n");
    printf("5. Americano\n");
    printf("Enter your selection:");

    int item_selection;
    scanf("%d", &item_selection);

    float total_price = 0.0;
    switch (item_selection)
    {
        case 1:
            total_price = 3.50;
            break;
        case 2:
            total_price = 4.00;
            break;
        case 3:
            total_price = 3.00;
            break;
        case 4:
            total_price = 2.50;
            break;
        case 5:
            total_price = 2.00;
            break;
        default:
            printf("Invalid selection!\n");
            break;
    }

    printf("Your total price is: $%.2f", total_price);

    printf("\nWould you like to add a tip? (Y/N): ");

    char tip_choice;
    scanf(" %c", &tip_choice);

    float tip_amount = 0.0;
    if (tip_choice == 'Y')
    {
        printf("Please enter the tip amount:");
        scanf("%f", &tip_amount);
        total_price += tip_amount;
    }

    printf("Your total bill is: $%.2f", total_price);

    system("pause");
    return 0;
}