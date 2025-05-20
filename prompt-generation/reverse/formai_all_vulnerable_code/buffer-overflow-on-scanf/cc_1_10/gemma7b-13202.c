//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("-----------------------\n");
    printf("   Coffee Menu\n");
    printf("-----------------------\n");
    printf("1. Espresso\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Americano\n");
    printf("-----------------------\n");
}

void calculate_bill(int item_no)
{
    int cost = 0;

    switch (item_no)
    {
        case 1:
            cost = 50;
            break;
        case 2:
            cost = 60;
            break;
        case 3:
            cost = 70;
            break;
        case 4:
            cost = 80;
            break;
        case 5:
            cost = 90;
            break;
    }

    printf("Your total cost is: $%d\n", cost);
}

int main()
{
    int item_no;

    display_menu();

    printf("Enter item number: ");
    scanf("%d", &item_no);

    calculate_bill(item_no);

    return 0;
}