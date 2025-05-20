//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no = 1;
    float total_amount = 0.0f;
    char customer_name[20];

    printf("Welcome to the Crazy Coffee Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("What would you like to order?\n");
    printf("1. Black Coffee\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("Enter item number: ");
    scanf("%d", &item_no);

    switch (item_no)
    {
        case 1:
            total_amount += 2.0f;
            printf("You ordered a black coffee.\n");
            break;
        case 2:
            total_amount += 3.0f;
            printf("You ordered a cappuccino.\n");
            break;
        case 3:
            total_amount += 3.5f;
            printf("You ordered a latte.\n");
            break;
        case 4:
            total_amount += 4.0f;
            printf("You ordered a mocha.\n");
            break;
        default:
            printf("Invalid item number.\n");
            break;
    }

    printf("Would you like to add any extras? (Y/N) ");
    char extra_order;
    scanf("%c", &extra_order);

    if (extra_order == 'Y')
    {
        printf("Please specify your extra order: ");
        char extra_order_details[50];
        scanf("%s", extra_order_details);

        total_amount += 1.0f;
        printf("You added %s to your order.\n", extra_order_details);
    }

    printf("Thank you, %s, for visiting the Crazy Coffee Cafe!\n", customer_name);
    printf("Total amount: $%.2f\n", total_amount);

    return 0;
}