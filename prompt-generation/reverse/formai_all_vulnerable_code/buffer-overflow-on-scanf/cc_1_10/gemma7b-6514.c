//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv_bill_system()
{
    system("CLS");
    printf("-----------------------------------------------------------------------\n");
    printf("                     WELCOME TO THE COFFEE HOUSE!\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Please select an item from the menu:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Mocktail\n");
    printf("Enter your choice:");

    char item_choice;
    scanf("%c", &item_choice);

    switch (item_choice)
    {
        case '1':
            printf("You selected Coffee.\n");
            break;
        case '2':
            printf("You selected Tea.\n");
            break;
        case '3':
            printf("You selected Juice.\n");
            break;
        case '4':
            printf("You selected Mocktail.\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    printf("Please enter the number of items:");

    int num_items;
    scanf("%d", &num_items);

    float total_cost = num_items * 2.50;

    printf("Your total cost is $%.2f.", total_cost);

    printf("\nThank you for your visit to the coffee house. Come again soon!");

    system("PAUSE");
}

int main()
{
    inv_bill_system();

    return 0;
}