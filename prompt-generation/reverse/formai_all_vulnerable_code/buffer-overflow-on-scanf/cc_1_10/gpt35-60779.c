//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float income;
    float expense;
    float balance = 0;
    int choice;

    printf("\n----- Personal Finance Planner -----\n\n");

    while (1)
    {
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter income: ");
                scanf("%f", &income);
                balance += income;
                printf("Income added successfully!\n\n");
                break;

            case 2:
                printf("\nEnter expense: ");
                scanf("%f", &expense);
                if (expense <= balance)
                {
                    balance -= expense;
                    printf("Expense added successfully!\n\n");
                }
                else
                {
                    printf("Not enough balance to add expense!\n\n");
                }
                break;

            case 3:
                printf("\nYour current balance is: %.2f\n\n", balance);
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }

    return 0;
}