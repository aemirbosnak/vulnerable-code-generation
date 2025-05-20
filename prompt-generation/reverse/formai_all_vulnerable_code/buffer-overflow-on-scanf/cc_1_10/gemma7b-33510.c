//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("Welcome to the Cool Coffee Cafe!\n");
    printf("Please select a drink:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothies\n");
    printf("Enter your selection:");
}

int main()
{
    int selection;
    float price;
    char name[20];

    display_menu();
    scanf("%d", &selection);

    switch (selection)
    {
        case 1:
            price = 2.50;
            break;
        case 2:
            price = 2.00;
            break;
        case 3:
            price = 1.50;
            break;
        case 4:
            price = 3.00;
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
    }

    printf("Please enter your name:");
    scanf("%s", name);

    printf("Thank you, %s, for your order. You have selected a %s, which costs $%.2f.\n", name, selection, price);

    printf("Please pay the total amount of $%.2f.", price);

    return 0;
}