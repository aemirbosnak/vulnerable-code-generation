//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct personal_finance_planner {
    char name[50];
    double income;
    double savings;
    double debt;
    double expenses;
    double emergency_fund;
    double retirement_savings;
};

void print_planner(struct personal_finance_planner planner) {
    printf("Name: %s\n", planner.name);
    printf("Income: $%.2lf\n", planner.income);
    printf("Savings: $%.2lf\n", planner.savings);
    printf("Debt: $%.2lf\n", planner.debt);
    printf("Expenses: $%.2lf\n", planner.expenses);
    printf("Emergency Fund: $%.2lf\n", planner.emergency_fund);
    printf("Retirement Savings: $%.2lf\n", planner.retirement_savings);
}

int main() {
    struct personal_finance_planner planner;

    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your savings: ");
    scanf("%lf", &planner.savings);

    printf("Enter your debt: ");
    scanf("%lf", &planner.debt);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    printf("Enter your emergency fund: ");
    scanf("%lf", &planner.emergency_fund);

    printf("Enter your retirement savings: ");
    scanf("%lf", &planner.retirement_savings);

    print_planner(planner);

    return 0;
}