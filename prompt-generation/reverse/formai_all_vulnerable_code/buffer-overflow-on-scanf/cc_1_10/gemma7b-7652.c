//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf("\n--- Coffee Menu ---\n");
    printf("1. Black Coffee - $1.50\n");
    printf("2. Cappuccino - $2.00\n");
    printf("3. Latte - $2.50\n");
    printf("4. Mocha - $3.00\n");
    printf("5. Frappuccino - $3.50\n");
    printf("\nPlease select a number:");
}

int main()
{
    int choice;
    float total_cost = 0.0f;

    print_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total_cost = 1.50f;
            break;
        case 2:
            total_cost = 2.00f;
            break;
        case 3:
            total_cost = 2.50f;
            break;
        case 4:
            total_cost = 3.00f;
            break;
        case 5:
            total_cost = 3.50f;
            break;
        default:
            printf("Invalid selection\n");
    }

    if (total_cost > 0.0f)
    {
        printf("Your total cost is: $%.2f\n", total_cost);
        printf("Please tender your payment.\n");
    }

    return 0;
}