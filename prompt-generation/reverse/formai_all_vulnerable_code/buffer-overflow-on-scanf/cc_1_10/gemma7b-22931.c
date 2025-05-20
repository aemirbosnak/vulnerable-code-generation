//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu()
{
    printf("\n--- The Electric Brew Menu ---\n");
    printf("1. Soy Latte - $5.00\n");
    printf("2. Caffe Latte - $4.00\n");
    printf("3. Cappuccino - $3.00\n");
    printf("4. Americano - $2.00\n");
    printf("5. Espresso - $1.00\n");
    printf("Enter your selection: ");
}

int main()
{
    int selection;
    float total_cost = 0.0;
    char name[20];

    printf("\nWelcome to The Electric Brew, where the coffee flows neon!\n");

    display_menu();
    scanf("%d", &selection);

    switch (selection)
    {
        case 1:
            total_cost = 5.0;
            break;
        case 2:
            total_cost = 4.0;
            break;
        case 3:
            total_cost = 3.0;
            break;
        case 4:
            total_cost = 2.0;
            break;
        case 5:
            total_cost = 1.0;
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
    }

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s, your total cost is $%.2f.\n", name, total_cost);
    printf("Thank you for visiting The Electric Brew. May the coffee be with you.\n");

    return 0;
}