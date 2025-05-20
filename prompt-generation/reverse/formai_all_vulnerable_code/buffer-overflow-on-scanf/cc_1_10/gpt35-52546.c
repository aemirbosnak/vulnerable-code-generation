//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>

// Function prototypes
void budgetPlanner();
void income();
void expenses();
void report();

// Declare variables
float totalIncome = 0, totalExpense = 0, savings = 0;
char choice;

int main()
{
    printf("\n\n Welcome to Personal Finance Planner \n\n");
    while (1)
    {
        printf("\n Enter your choice: \n\n");
        printf(" 1. Budget Planner \n 2. Income \n 3. Expenses \n 4. Report \n 5. Exit \n\n");
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                budgetPlanner();
                break;
            case '2':
                income();
                break;
            case '3':
                expenses();
                break;
            case '4':
                report();
                break;
            case '5':
                return 0;
            default:
                printf("\n Invalid choice! \n");
                break;
        }
    }
    return 0;
}

// Function definitions

void budgetPlanner()
{
    printf("\n\n Enter your monthly income and expenses \n\n");
    printf(" Monthly Income: ");
    scanf("%f", &totalIncome);
    printf("\n Monthly Expenses: ");
    scanf("%f", &totalExpense);
    savings = totalIncome - totalExpense;
    printf("\n Monthly Savings: $%.2f \n", savings);
}

void income()
{
    float incomeAmount;
    printf("\n Enter the amount of income: ");
    scanf("%f", &incomeAmount);
    totalIncome += incomeAmount;
    printf("\n Income added successfully! \n");
}

void expenses()
{
    float expenseAmount;
    printf("\n Enter the amount of expense: ");
    scanf("%f", &expenseAmount);
    totalExpense += expenseAmount;
    printf("\n Expense added successfully! \n");
}

void report()
{
    printf("\n Total Income: $%.2f \n", totalIncome);
    printf("\n Total Expenses: $%.2f \n", totalExpense);
    printf("\n Monthly Savings: $%.2f \n", savings);
}