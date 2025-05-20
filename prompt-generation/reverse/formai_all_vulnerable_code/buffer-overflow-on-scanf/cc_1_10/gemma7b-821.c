//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("\nWelcome to the Coffee Cafe!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");
    printf("5. Pastry\n");
    printf("6. Bread\n");
    printf("7. Water\n");
    printf("Enter your selection: ");
}

int main()
{
    int item_no;
    float total_cost = 0.0f;
    char name[20];

    display_menu();
    scanf("%d", &item_no);

    switch (item_no)
    {
        case 1:
            total_cost += 5.0f;
            break;
        case 2:
            total_cost += 4.0f;
            break;
        case 3:
            total_cost += 3.0f;
            break;
        case 4:
            total_cost += 6.0f;
            break;
        case 5:
            total_cost += 2.0f;
            break;
        case 6:
            total_cost += 1.0f;
            break;
        case 7:
            total_cost += 0.5f;
            break;
        default:
            printf("Invalid item selection.\n");
            break;
    }

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Thank you, %s, for your order. Your total cost is: $%.2f", name, total_cost);

    return 0;
}