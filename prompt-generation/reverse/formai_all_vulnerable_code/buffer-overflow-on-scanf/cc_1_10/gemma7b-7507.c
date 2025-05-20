//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void display_menu()
{
    printf("\nWelcome to Coffee Haven!");
    printf("\nPlease select an option:");
    printf("\n1. Coffee");
    printf("\n2. Tea");
    printf("\n3. Juice");
    printf("\n4. Snacks");
    printf("\n5. Exit");
}

int main()
{
    int choice;
    float total_amount = 0.0f;
    char name[20];

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total_amount += 2.50f;
            printf("You selected Coffee. Price: $2.50\n");
            break;
        case 2:
            total_amount += 2.00f;
            printf("You selected Tea. Price: $2.00\n");
            break;
        case 3:
            total_amount += 1.50f;
            printf("You selected Juice. Price: $1.50\n");
            break;
        case 4:
            total_amount += 1.00f;
            printf("You selected Snacks. Price: $1.00\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid selection.\n");
    }

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("\nThank you, %s, for your order. Total amount: $%.2f", name, total_amount);

    return 0;
}