//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void greet(char name)
{
    printf("Hey, %c! Welcome to the Caffeinated Cave!\n", name);
}

int main()
{
    char name;
    printf("What's your name, my dear customer? ");
    scanf("%s", &name);
    greet(name);

    int order;
    printf("What's your order, buster? (1 for Coffee, 2 for Tea, 3 for Smoothies)\n");
    scanf("%d", &order);

    float total = 0.0f;
    switch (order)
    {
        case 1:
            total = 2.50f;
            break;
        case 2:
            total = 3.25f;
            break;
        case 3:
            total = 4.00f;
            break;
        default:
            printf("Invalid order, punk!\n");
            exit(1);
    }

    printf("Your total is: $%.2f\n", total);

    char payment;
    printf("How will you pay? (C for Cash, M for Magic Bean)\n");
    scanf("%s", &payment);

    switch (payment)
    {
        case 'C':
            printf("Thanks for your cash, %c!\n", name);
            break;
        case 'M':
            printf("You're a wizard, %c! We'll give you a free slice of pie.\n", name);
            total = total - 0.50f;
            break;
        default:
            printf("Invalid payment method, go away!\n");
            exit(1);
    }

    printf("Enjoy your beverage, %c! We'll see you next time.\n", name);

    return 0;
}