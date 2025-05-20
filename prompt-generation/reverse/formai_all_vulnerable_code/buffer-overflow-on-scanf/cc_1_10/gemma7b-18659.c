//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Shockin' Coffee Cafe!\n");
    printf("-----------------------\n");

    int choice = 0;
    float total = 0.0f;

    printf("Please select an item:\n");
    printf("1. Black Coffee - $2.00\n");
    printf("2. Cappuccino - $3.00\n");
    printf("3. Latte - $4.00\n");
    printf("4. Mocha - $5.00\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            total += 2.00f;
            printf("You selected Black Coffee!\n");
            break;
        case 2:
            total += 3.00f;
            printf("You selected Cappuccino!\n");
            break;
        case 3:
            total += 4.00f;
            printf("You selected Latte!\n");
            break;
        case 4:
            total += 5.00f;
            printf("You selected Mocha!\n");
            break;
        default:
            printf("Invalid selection.\n");
    }

    printf("Please enter the number of servings:** ");
    int servings = 0;
    scanf("%d", &servings);

    total *= servings;

    printf("Total cost: $%.2f\n", total);

    system("pause");
    return 0;
}