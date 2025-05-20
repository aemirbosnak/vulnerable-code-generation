//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float balance, expenses, income;
    int choice;
    char option;

    printf("Welcome to Personal Finance Planner\n");

    do
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Check balance\n");
        printf("2. Record expenses\n");
        printf("3. Record income\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Your current balance is $%.2f.\n", balance);
                break;
            case 2:
                printf("How much did you spend today?\n");
                scanf("%f", &expenses);
                balance -= expenses;
                printf("Your new balance is $%.2f.\n", balance);
                break;
            case 3:
                printf("How much did you earn today?\n");
                scanf("%f", &income);
                balance += income;
                printf("Your new balance is $%.2f.\n", balance);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Would you like to continue? (y/n)\n");
        scanf(" %c", &option);

    } while (option == 'y' || option == 'Y');

    printf("Thank you for using Personal Finance Planner!\n");

    return 0;
}