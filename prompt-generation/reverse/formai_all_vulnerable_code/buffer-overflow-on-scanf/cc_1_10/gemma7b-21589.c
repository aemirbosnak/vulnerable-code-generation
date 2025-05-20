//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("-------------------------\n");
    printf("   WELCOME TO THE COFFEE HOUSE!\n");
    printf("-------------------------\n");

    int coffee_type;
    float price;
    char name[20];

    printf("Please choose your coffee type:\n");
    printf("1. Espresso\n");
    printf("2. Latte\n");
    printf("3. Cappuccino\n");
    printf("4. Macchiato\n");
    scanf("%d", &coffee_type);

    switch (coffee_type)
    {
        case 1:
            price = 3.50;
            break;
        case 2:
            price = 4.00;
            break;
        case 3:
            price = 4.50;
            break;
        case 4:
            price = 5.00;
            break;
        default:
            printf("Invalid choice\n");
            exit(1);
    }

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Here is your order, %s, you have chosen a %s and the total price is $%.2f\n", name, coffee_type, price);

    printf("Would you like to add any additional items to your order? (Y/N) ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y')
    {
        // Add additional items to the order
        printf("Please enter the name of the additional item: ");
        char additional_item[20];
        scanf("%s", additional_item);

        printf("Please enter the price of the additional item: ");
        float additional_price;
        scanf("%f", &additional_price);

        printf("Your total order is: %s, %s, and %s for a total price of $%.2f\n", name, coffee_type, additional_item, price + additional_price);
    }
    else
    {
        printf("Thank you for your order, %s!\n", name);
    }

    return 0;
}