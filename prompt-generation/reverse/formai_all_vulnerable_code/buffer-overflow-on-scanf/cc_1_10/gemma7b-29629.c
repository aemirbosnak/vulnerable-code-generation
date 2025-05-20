//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu()
{
    printf("Welcome to Coffee Heaven!\n\n");
    printf("Please select a beverage:\n");
    printf("1. Espresso\n");
    printf("2. Latte\n");
    printf("3. Cappuccino\n");
    printf("4. Macchiato\n");
    printf("5. Mocha\n");
    printf("Please enter your selection:");
}

int main()
{
    int choice;
    float total = 0.0f;
    char name[20];

    displayMenu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total += 3.0f;
            break;
        case 2:
            total += 4.0f;
            break;
        case 3:
            total += 5.0f;
            break;
        case 4:
            total += 6.0f;
            break;
        case 5:
            total += 7.0f;
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    printf("Please enter your name:");
    scanf("%s", name);

    printf("Hello, %s, your total is $%.2f.\n", name, total);

    return 0;
}