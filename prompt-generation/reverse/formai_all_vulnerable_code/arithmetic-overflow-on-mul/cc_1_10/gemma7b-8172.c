//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void bill_calc()
{
    int item_no, qty, price, total_amount = 0;
    char item_name[20];

    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter item name: ");
    scanf("%s", item_name);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    printf("Enter item price: ");
    scanf("%d", &price);

    total_amount = qty * price;

    printf("Total amount: $%d", total_amount);

    printf("\nThank you for your purchase!");
}

int main()
{
    int choice;

    printf("Welcome to the Coffee Bean Cafe!");
    printf("\nPlease select an option:");
    printf("\n1. Place Order");
    printf("\n2. View Menu");
    printf("\n3. Exit");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            bill_calc();
            break;
        case 2:
            // Code to display menu
            break;
        case 3:
            // Code to exit
            break;
        default:
            printf("Invalid input!");
    }

    return 0;
}