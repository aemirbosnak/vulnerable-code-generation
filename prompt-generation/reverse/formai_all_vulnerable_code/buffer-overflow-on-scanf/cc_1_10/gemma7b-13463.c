//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu()
{
    printf("-------------------------------------------------------\n");
    printf("Welcome to the Coffee House!\n");
    printf("-------------------------------------------------------\n");
    printf("1. Americano\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Espresso\n");
    printf("Please enter your choice:");
}

void calculate_bill(int choice)
{
    float price = 0;
    switch (choice)
    {
        case 1:
            price = 50.0;
            break;
        case 2:
            price = 60.0;
            break;
        case 3:
            price = 70.0;
            break;
        case 4:
            price = 80.0;
            break;
        case 5:
            price = 90.0;
            break;
    }

    printf("Your total bill is: $%.2f\n", price);
}

int main()
{
    display_menu();
    int choice = 0;
    scanf("%d", &choice);
    calculate_bill(choice);

    return 0;
}