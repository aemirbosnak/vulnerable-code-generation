//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>

int main() {
    // Monthly income and expenses
    float monthly_income, rent, utilities, food, transportation, other_expenses;
    printf("Enter your monthly income: ");
    scanf("%f", &monthly_income);

    printf("\nEnter your monthly rent: ");
    scanf("%f", &rent);

    printf("\nEnter your monthly utilities cost: ");
    scanf("%f", &utilities);

    printf("\nEnter your monthly food expenses: ");
    scanf("%f", &food);

    printf("\nEnter your monthly transportation costs: ");
    scanf("%f", &transportation);

    printf("\nEnter any other monthly expenses: ");
    scanf("%f", &other_expenses);

    // Total monthly expenses and leftover income
    float total_expenses = rent + utilities + food + transportation + other_expenses;
    float leftover_income = monthly_income - total_expenses;

    printf("\nYour total monthly expenses is $%.2f", total_expenses);
    printf("\nYour leftover income is $%.2f", leftover_income);

    // Savings calculations
    float saving_rate;
    printf("\nEnter the percentage of your leftover income you want to save (exclude the % sign): ");
    scanf("%f", &saving_rate);

    float saving_amount = (saving_rate / 100) * leftover_income;

    printf("\nYou will be saving $%.2f per month", saving_amount);

    // Debt calculations
    float current_debt, debt_interest_rate, debt_monthly_payment;
    printf("\nEnter the amount of debt you currently have: ");
    scanf("%f", &current_debt);

    printf("\nEnter the annual interest rate for your debt (exclude the % sign): ");
    scanf("%f", &debt_interest_rate);

    float monthly_interest_rate = (debt_interest_rate / 12) / 100;

    printf("\nYour monthly interest rate is %.2f", monthly_interest_rate);

    printf("\nEnter the monthly payment you can afford for your debt: ");
    scanf("%f", &debt_monthly_payment);

    float remaining_debt = current_debt;
    int months_to_pay_off_debt = 0;

    while (remaining_debt > 0) {
        months_to_pay_off_debt++;

        float interest_payment = remaining_debt * monthly_interest_rate;
        float principal_payment = debt_monthly_payment - interest_payment;

        if (principal_payment > remaining_debt) {
            principal_payment = remaining_debt;
            remaining_debt = 0;
        } else {
            remaining_debt -= principal_payment;
        }
    }

    printf("\nYou will be debt-free in %d months", months_to_pay_off_debt);

    return 0;
}