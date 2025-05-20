//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void takeOrder();
void calculateBill();

int main()
{
    displayMenu();
    takeOrder();
    calculateBill();

    return 0;
}

void displayMenu()
{
    printf("**Welcome to Caffeinated Dreams!**\n");
    printf("-----------------------\n");
    printf("1. Latte\n");
    printf("2. Cappuccino\n");
    printf("3. Americano\n");
    printf("4. Espresso\n");
    printf("5. Mocha\n");
    printf("Please select a drink: ");
}

void takeOrder()
{
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You selected a latte.\n");
            break;
        case 2:
            printf("You selected a cappuccino.\n");
            break;
        case 3:
            printf("You selected an Americano.\n");
            break;
        case 4:
            printf("You selected an espresso.\n");
            break;
        case 5:
            printf("You selected a mocha.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void calculateBill()
{
    int quantity;
    float price, totalBill = 0;

    printf("Enter the quantity of your drink: ");
    scanf("%d", &quantity);

    switch (quantity)
    {
        case 1:
            price = 2.50;
            break;
        case 2:
            price = 3.00;
            break;
        case 3:
            price = 3.50;
            break;
        case 4:
            price = 4.00;
            break;
        default:
            price = 0.00;
            break;
    }

    totalBill = quantity * price;

    printf("Your total bill is: $%.2f\n", totalBill);
}