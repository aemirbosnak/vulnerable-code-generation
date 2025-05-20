//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("\nWelcome to Caffeinated Dreams!\n\n");
    printf("--------------------\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Macchiato\n");
    printf("--------------------\n");
    printf("Please select an item: ");
}

int main()
{
    int item_no;
    float total_cost = 0;

    display_menu();
    scanf("%d", &item_no);

    switch (item_no)
    {
        case 1:
            total_cost = 3.50;
            break;
        case 2:
            total_cost = 4.00;
            break;
        case 3:
            total_cost = 3.00;
            break;
        case 4:
            total_cost = 3.25;
            break;
        case 5:
            total_cost = 3.75;
            break;
        default:
            printf("Invalid item number.\n");
            break;
    }

    if (total_cost > 0)
    {
        printf("Total cost: $%.2f\n", total_cost);
        printf("Please pay the amount: $");
        float payment;
        scanf("%f", &payment);

        if (payment < total_cost)
        {
            printf("Insufficient funds.\n");
        }
        else
        {
            printf("Change: $%.2f\n", payment - total_cost);
        }
    }

    return 0;
}