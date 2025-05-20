//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initializing variables
    float balance, income, expenses;
    int choice;

    // Taking user input
    printf("Enter your balance: ");
    scanf("%f", &balance);
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    // Displaying user options
    printf("\nWhat would you like to do?\n");
    printf("1. Add income\n");
    printf("2. Add expense\n");
    printf("3. View balance\n");
    printf("4. Exit\n");

    while (1) // Running indefinitely until user chooses to exit
    {
        // Taking user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                float additional_income;
                printf("Enter additional income: ");
                scanf("%f", &additional_income);
                income += additional_income;
                printf("\nIncome added successfully!\n\n");
                break;
            }

            case 2:
            {
                float additional_expense;
                printf("Enter additional expense: ");
                scanf("%f", &additional_expense);
                if (additional_expense <= balance)
                {
                    balance -= additional_expense;
                    expenses += additional_expense;
                    printf("\nExpense added successfully!\n\n");
                }
                else
                {
                    printf("\nInsufficient balance!\n\n");
                }
                break;
            }

            case 3:
            {
                printf("\nYour current balance is: %.2f\n", balance);
                printf("Your monthly income is: %.2f\n", income);
                printf("Your monthly expenses are: %.2f\n\n", expenses);
                break;
            }

            case 4:
            {
                printf("\nExiting Personal Finance Planner. Thank you!\n");
                exit(0); // Exiting the program with status 0 (success)
            }

            default:
            {
                printf("\nInvalid choice! Please try again.\n\n");
                break;
            }
        }

        // Displaying user options again
        printf("What would you like to do?\n");
        printf("1. Add income\n");
        printf("2. Add expense\n");
        printf("3. View balance\n");
        printf("4. Exit\n");
    }

    return 0; // Returning 0 to indicate program success
}