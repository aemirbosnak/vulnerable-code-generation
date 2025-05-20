//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Income {
    float salary;
    float investments;
    float other;
};

struct Expense {
    float housing;
    float food;
    float transportation;
    float healthcare;
    float other;
};

struct Budget {
    struct Income income;
    struct Expense expense;
    float savings;
    float net_income;
};

void calculate_net_income(struct Budget *budget) {
    budget->net_income = budget->income.salary + budget->income.investments + budget->income.other - budget->expense.housing - budget->expense.food - budget->expense.transportation - budget->expense.healthcare - budget->expense.other;
}

void calculate_savings(struct Budget *budget, float savings_rate) {
    budget->savings = savings_rate * budget->net_income;
}

void print_budget(struct Budget budget) {
    printf("Income:\n");
    printf(" - Salary: $%.2f\n", budget.income.salary);
    printf(" - Investments: $%.2f\n", budget.income.investments);
    printf(" - Other: $%.2f\n", budget.income.other);
    printf("\n");
    printf("Expenses:\n");
    printf(" - Housing: $%.2f\n", budget.expense.housing);
    printf(" - Food: $%.2f\n", budget.expense.food);
    printf(" - Transportation: $%.2f\n", budget.expense.transportation);
    printf(" - Healthcare: $%.2f\n", budget.expense.healthcare);
    printf(" - Other: $%.2f\n", budget.expense.other);
    printf("\n");
    printf("Savings: $%.2f\n", budget.savings);
    printf("Net Income: $%.2f\n", budget.net_income);
}

int main() {
    struct Budget budget;

    // Get user input
    printf("Enter your monthly salary: $");
    scanf("%f", &budget.income.salary);
    printf("Enter your monthly investment income: $");
    scanf("%f", &budget.income.investments);
    printf("Enter any other monthly income: $");
    scanf("%f", &budget.income.other);
    printf("Enter your monthly housing expenses: $");
    scanf("%f", &budget.expense.housing);
    printf("Enter your monthly food expenses: $");
    scanf("%f", &budget.expense.food);
    printf("Enter your monthly transportation expenses: $");
    scanf("%f", &budget.expense.transportation);
    printf("Enter your monthly healthcare expenses: $");
    scanf("%f", &budget.expense.healthcare);
    printf("Enter any other monthly expenses: $");
    scanf("%f", &budget.expense.other);

    // Calculate net income
    calculate_net_income(&budget);

    // Calculate savings
    float savings_rate;
    printf("Enter your desired savings rate: ");
    scanf("%f", &savings_rate);
    calculate_savings(&budget, savings_rate);

    // Print budget
    print_budget(budget);

    return 0;
}