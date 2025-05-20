//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void calculate_bill(int quantity, float price);

int main()
{
    int choice, quantity;
    float price;

    printf("Welcome to the Coffee Shop!\n");
    printf("Please select your choice:\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");

    scanf("%d", &choice);

    switch (choice)
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
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Enter the quantity of your order: ");
    scanf("%d", &quantity);

    calculate_bill(quantity, price);

    return 0;
}

void calculate_bill(int quantity, float price)
{
    int total_amount = quantity * price;
    float tax = total_amount * 0.10f;
    float total_bill = total_amount + tax;

    printf("Total amount: $%d\n", total_amount);
    printf("Tax: $%f\n", tax);
    printf("Total bill: $%f\n", total_bill);
}