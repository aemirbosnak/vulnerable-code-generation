//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct budget
{
    char name[50];
    float balance;
    float income;
    float expenses[4];
    int num_expenses;
};

void display_menu()
{
    printf("1. Add income\n");
    printf("2. Add expense\n");
    printf("3. Display budget\n");
    printf("4. Exit\n");
}

int main()
{
    struct budget budget;
    int choice;

    while (1)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter income: ");
                scanf("%f", &budget.income);
                break;
            case 2:
                printf("Enter expense: ");
                scanf("%f", &budget.expenses[budget.num_expenses]);
                budget.num_expenses++;
                break;
            case 3:
                printf("Name: %s\n", budget.name);
                printf("Balance: %.2f\n", budget.balance);
                printf("Income: %.2f\n", budget.income);
                printf("Expenses:\n");
                for (int i = 0; i < budget.num_expenses; i++)
                    printf("  %.2f\n", budget.expenses[i]);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}