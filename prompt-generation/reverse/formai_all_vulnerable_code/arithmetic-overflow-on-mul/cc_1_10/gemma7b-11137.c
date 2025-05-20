//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, quantity, i, total = 0;
    char name[20];

    system("cls");

    printf("Welcome to Cafe ABC!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Please enter the quantity of coffee: ");
            scanf("%d", &quantity);
            total += quantity * 50;
            break;
        case 2:
            printf("Please enter the quantity of tea: ");
            scanf("%d", &quantity);
            total += quantity * 40;
            break;
        case 3:
            printf("Please enter the quantity of juice: ");
            scanf("%d", &quantity);
            total += quantity * 30;
            break;
        case 4:
            printf("Please enter the quantity of smoothie: ");
            scanf("%d", &quantity);
            total += quantity * 60;
            break;
        default:
            printf("Invalid choice.\n");
    }

    system("cls");

    printf("Thank you, %s! Your total order is: $%d\n", name, total);
    printf("Please pay the amount and enjoy your drink!");

    return;
}