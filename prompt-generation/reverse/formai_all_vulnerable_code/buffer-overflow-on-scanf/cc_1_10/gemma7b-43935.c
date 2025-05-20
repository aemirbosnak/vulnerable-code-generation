//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("\nWelcome to the Cozy Coffee Cafe!\n");
    printf("------------------------\n");
    printf("1. Latte\n");
    printf("2. Cappuccino\n");
    printf("3. Americano\n");
    printf("4. Mocha\n");
    printf("5. Espresso\n");
    printf("------------------------\n");
}

int main()
{
    int choice, quantity;
    float total_cost = 0.0;

    display_menu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total_cost += 2.50 * quantity;
            break;
        case 2:
            total_cost += 3.00 * quantity;
            break;
        case 3:
            total_cost += 2.00 * quantity;
            break;
        case 4:
            total_cost += 3.50 * quantity;
            break;
        case 5:
            total_cost += 4.00 * quantity;
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    printf("Your total cost is: $%.2f\n", total_cost);

    return 0;
}