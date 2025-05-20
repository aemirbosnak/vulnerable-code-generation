//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>

float get_amount_savings(float income, float expenses) {
    return income - expenses;
}

float get_monthly_expenses(float monthly_rent, float utility_bills, float grocery_expenses, 
                           float transportation_cost, float entertainment_expenses, float other_expenses) {
    return monthly_rent + utility_bills + grocery_expenses + transportation_cost + entertainment_expenses + other_expenses;
}

float get_emergency_fund(float monthly_expenses) {
    return monthly_expenses * 3;
}

void display_financial_plan(float amount_savings, float monthly_expenses, float emergency_fund) {
    printf("----------------------------------------------------\n");
    printf("-------------- PERSONAL FINANCE PLANNER ------------\n");
    printf("----------------------------------------------------\n");
    printf("\n");
    printf("Amount Saved:              $%.2f\n", amount_savings);
    printf("Monthly Expenses:          $%.2f\n", monthly_expenses);
    printf("Emergency Fund:            $%.2f\n", emergency_fund);
}

int main() {
    float income, monthly_rent, utility_bills, grocery_expenses, transportation_cost, entertainment_expenses, other_expenses;

    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly rent/mortgage: ");
    scanf("%f", &monthly_rent);
    printf("Enter your monthly utility bills: ");
    scanf("%f", &utility_bills);
    printf("Enter your monthly grocery expenses: ");
    scanf("%f", &grocery_expenses);
    printf("Enter your monthly transportation cost: ");
    scanf("%f", &transportation_cost);
    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment_expenses);
    printf("Enter your other monthly expenses: ");
    scanf("%f", &other_expenses);

    float monthly_expenses = get_monthly_expenses(monthly_rent, utility_bills, grocery_expenses, transportation_cost, entertainment_expenses, other_expenses);
    float amount_savings = get_amount_savings(income, monthly_expenses);
    float emergency_fund = get_emergency_fund(monthly_expenses);

    display_financial_plan(amount_savings, monthly_expenses, emergency_fund);

    return 0;
}