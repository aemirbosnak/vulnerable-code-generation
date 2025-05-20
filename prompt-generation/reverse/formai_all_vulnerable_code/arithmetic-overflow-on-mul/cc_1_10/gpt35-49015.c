//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[50];
    int qty, choice, total=0, grandtotal=0;
    printf("\t\tWelcome to Cafe Billing System\n");
    printf("\nEnter your name:\n");
    scanf("%s", name);
    do
    {
        printf("\n========= Menu =========\n");
        printf("1. Coffee - Rs. 25\n");
        printf("2. Tea - Rs. 20\n");
        printf("3. Sandwich - Rs. 50\n");
        printf("4. Burger - Rs. 70\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the quantity of Coffee: ");
                scanf("%d", &qty);
                total = qty * 25;
                printf("Total amount is: Rs.%d\n", total);
                grandtotal = grandtotal + total;
                break;

            case 2:
                printf("\nEnter the quantity of Tea: ");
                scanf("%d", &qty);
                total = qty * 20;
                printf("Total amount is: Rs.%d\n", total);
                grandtotal = grandtotal + total;
                break;

            case 3:
                printf("\nEnter the quantity of Sandwich: ");
                scanf("%d", &qty);
                total = qty * 50;
                printf("Total amount is: Rs.%d\n", total);
                grandtotal = grandtotal + total;
                break;

            case 4:
                printf("\nEnter the quantity of Burger: ");
                scanf("%d", &qty);
                total = qty * 70;
                printf("Total amount is: Rs.%d\n", total);
                grandtotal = grandtotal + total;
                break;

            case 5:
                printf("\n\tThank you for dining with us, %s!\n", name);
                exit(0);

            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    } while (choice != 5);

    printf("\nGrand Total: Rs.%d\n", grandtotal);
    printf("\n\tThank you for dining with us, %s!\n", name);
    return 0;
}