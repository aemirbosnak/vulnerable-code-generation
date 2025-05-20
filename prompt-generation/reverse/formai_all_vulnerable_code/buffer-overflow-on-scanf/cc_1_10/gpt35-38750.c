//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, qty;
    float total = 0.0f, price;

    printf("Welcome to Cafe Billing System\n");
    printf("****************************\n");

    do
    {
        printf("Please select your order:\n");
        printf("1. Coffee\t\t$2.50\n");
        printf("2. Tea\t\t\t$1.75\n");
        printf("3. Sandwich\t\t$4.50\n");
        printf("4. Cake\t\t\t$3.50\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                price = qty * 2.50;
                total += price;
                printf("Price for Coffee: $%.2f\n", price);
                break;

            case 2:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                price = qty * 1.75;
                total += price;
                printf("Price for Tea: $%.2f\n", price);
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                price = qty * 4.50;
                total += price;
                printf("Price for Sandwich: $%.2f\n", price);
                break;

            case 4:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                price = qty * 3.50;
                total += price;
                printf("Price for Cake: $%.2f\n", price);
                break;

            case 5:
                printf("Thank you for using Cafe Billing System!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");

    } while (choice != 5);

    printf("Total bill amount: $%.2f\n", total);

    return 0;
}