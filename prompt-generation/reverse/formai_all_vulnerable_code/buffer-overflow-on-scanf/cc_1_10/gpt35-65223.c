//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>

float get_income() {
    float income;
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    return income;
}

float get_expenses() {
    float expenses;
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    return expenses;
}

float compute_savings(float income, float expenses) {
    float savings = income - expenses;
    return savings;
}

void print_savings(float savings) {
    printf("Your monthly savings is $%.2f\n", savings);
}

void print_monthly_budget(float income, float expenses) {
    printf("Your monthly budget is $%.2f\n", income - expenses);
}

void print_yearly_budget(float income, float expenses) {
    printf("Your yearly budget is $%.2f\n", 12 * (income - expenses));
}

void print_budget_status(float savings) {
    if(savings > 0) {
        printf("Great job! You are living within your means and saving money.\n");
    } else if(savings == 0) {
        printf("You are living within your means but not saving any money.\n");
    } else {
        printf("You are spending more than you are earning. You need to reassess your expenses.\n");
    }
}

int main() {
    printf("*********************\n");
    printf("* Personal Finance Planner *\n");
    printf("*********************\n\n");

    float income = get_income();
    float expenses = get_expenses();
    float savings = compute_savings(income, expenses);

    printf("\n");

    print_savings(savings);
    print_monthly_budget(income, expenses);
    print_yearly_budget(income, expenses);
    print_budget_status(savings);

    return 0;
}