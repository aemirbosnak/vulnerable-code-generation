//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void menu();
void billing();

int main()
{
    int choice;
    printf("\tWelcome to C Cafe Billing System\n");
    printf("----------------------------------------\n\n");
    do
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        billing(choice);
    }
    while (choice != 4);
    return 0;
}

void menu()
{
    printf("\nMENU:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Snacks\n");
    printf("4. Exit\n");
}

void billing(int choice)
{
    float price;
    switch(choice)
    {
        case 1:
            printf("\nYou've ordered Coffee\n");
            printf("Price: 2.50\n");
            price = 2.50;
            break;
        case 2:
            printf("\nYou've ordered Tea\n");
            printf("Price: 1.50\n");
            price = 1.50;
            break;
        case 3:
            printf("\nYou've ordered Snacks\n");
            printf("Price: 3.00\n");
            price = 3.00;
            break;
        case 4:
            printf("\nThank you for visiting C Cafe Billing System\n");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice. Please try again\n");
            return;
    }
    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    float total = price * quantity;
    printf("\nTotal Price: %.2f\n", total);
}