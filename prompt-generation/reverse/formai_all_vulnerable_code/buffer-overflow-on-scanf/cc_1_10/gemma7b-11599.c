//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void displayMenu()
{
    printf("\n**Coffee Menu:**\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Frappuccino\n");
    printf("Please enter the number of your choice:");
}

void calculatePrice(int choice)
{
    switch (choice)
    {
        case 1:
            printf("Price: $3.00\n");
            break;
        case 2:
            printf("Price: $3.50\n");
            break;
        case 3:
            printf("Price: $4.00\n");
            break;
        case 4:
            printf("Price: $4.50\n");
            break;
        case 5:
            printf("Price: $5.00\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

int main()
{
    int choice;

    displayMenu();
    scanf("%d", &choice);

    calculatePrice(choice);

    return 0;
}