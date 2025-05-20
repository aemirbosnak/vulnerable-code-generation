//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct PersonalFinancePlanner
{
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
    double debt;
};

int main()
{
    struct PersonalFinancePlanner planner;

    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    printf("Enter your savings: ");
    scanf("%lf", &planner.savings);

    printf("Enter your investments: ");
    scanf("%lf", &planner.investments);

    printf("Enter your debt: ");
    scanf("%lf", &planner.debt);

    printf("Personal Finance Planner Report:\n");

    printf("Name: %s\n", planner.name);

    printf("Age: %d\n", planner.age);

    printf("Income: %.2lf\n", planner.income);

    printf("Expenses: %.2lf\n", planner.expenses);

    printf("Savings: %.2lf\n", planner.savings);

    printf("Investments: %.2lf\n", planner.investments);

    printf("Debt: %.2lf\n", planner.debt);

    return 0;
}