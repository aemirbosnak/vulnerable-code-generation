//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_BUDGET 100000
#define MAX_INCOME 100000
#define MAX_EXPENSES 10000
#define MAX_SAVINGS 10000
#define MAX_DEBT 10000

struct budget {
    int income;
    int expenses;
    int savings;
    int debt;
};

struct personal_finance_planner {
    struct budget budget;
    int savings_goal;
    int debt_goal;
    int savings_rate;
    int debt_rate;
};

void print_budget(struct budget b) {
    printf("Income: %d\n", b.income);
    printf("Expenses: %d\n", b.expenses);
    printf("Savings: %d\n", b.savings);
    printf("Debt: %d\n", b.debt);
}

void print_personal_finance_planner(struct personal_finance_planner p) {
    printf("Savings Goal: %d\n", p.savings_goal);
    printf("Debt Goal: %d\n", p.debt_goal);
    printf("Savings Rate: %d\n", p.savings_rate);
    printf("Debt Rate: %d\n", p.debt_rate);
}

int main() {
    struct budget b = {.income = 0, .expenses = 0, .savings = 0, .debt = 0};
    struct personal_finance_planner p = {.savings_goal = 0, .debt_goal = 0, .savings_rate = 0, .debt_rate = 0};

    printf("Enter Income: ");
    scanf("%d", &b.income);
    printf("Enter Expenses: ");
    scanf("%d", &b.expenses);
    printf("Enter Savings: ");
    scanf("%d", &b.savings);
    printf("Enter Debt: ");
    scanf("%d", &b.debt);

    printf("Enter Savings Goal: ");
    scanf("%d", &p.savings_goal);
    printf("Enter Debt Goal: ");
    scanf("%d", &p.debt_goal);
    printf("Enter Savings Rate: ");
    scanf("%d", &p.savings_rate);
    printf("Enter Debt Rate: ");
    scanf("%d", &p.debt_rate);

    print_budget(b);
    print_personal_finance_planner(p);

    return 0;
}