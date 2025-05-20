//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
// Personal Finance Planner Example Program

#include <stdio.h>

int main()
{
    int total_income = 0; // Total Income
    int total_expenses = 0; // Total Expenses
    int balance = 0; // Balance

    // Collect Income
    printf("Enter your income: ");
    scanf("%d", &total_income);

    // Collect Expenses
    printf("Enter your expenses: ");
    scanf("%d", &total_expenses);

    // Calculate balance
    balance = total_income - total_expenses;

    // Check Balance
    if(balance > 0)
    {
        printf("You have a total of %d dollars left over.\n", balance);
    }
    else if(balance == 0)
    {
        printf("You have no money left over.\n");
    }
    else
    {
        printf("You are in debt of %d dollars.\n", balance);
    }
    
    // Suggestion based on balance
    if(balance > 500)
    {
        printf("You are doing great at saving money!\n");
    }
    else if(balance > 0 && balance <= 500)
    {
        printf("Keep up the good work, but try to save a little more if possible.\n");
    }
    else
    {
        printf("You should consider cutting down on expenses or finding ways to increase income.\n");
    }

    return 0;
}