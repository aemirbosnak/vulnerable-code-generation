//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>

/* Function prototypes */
float calculate_total_income(float monthly_salary, float monthly_bonus);
float calculate_monthly_expenses(float rent, float utilities, float groceries, float transportation, float misc);
float calculate_savings(float total_income, float monthly_expenses);

/* Main function */
int main(void) {
    /* Variable declarations */
    float monthly_salary, monthly_bonus, rent, utilities, groceries, transportation, misc;
    float total_income, monthly_expenses, savings;

    /* Get user inputs */
    printf("Enter your monthly salary: ");
    scanf("%f", &monthly_salary);
    printf("Enter your monthly bonus: ");
    scanf("%f", &monthly_bonus);
    printf("Enter your monthly rent: ");
    scanf("%f", &rent);
    printf("Enter your monthly utilities (electricity, water, etc.): ");
    scanf("%f", &utilities);
    printf("Enter your monthly grocery expenses: ");
    scanf("%f", &groceries);
    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);
    printf("Enter your monthly miscellaneous expenses: ");
    scanf("%f", &misc);

    /* Calculate financial values */
    total_income = calculate_total_income(monthly_salary, monthly_bonus);
    monthly_expenses = calculate_monthly_expenses(rent, utilities, groceries, transportation, misc);
    savings = calculate_savings(total_income, monthly_expenses);

    /* Display financial information */
    printf("\n\n----- PERSONAL FINANCE PLANNER -----");
    printf("\nTotal income: $%.2f", total_income);
    printf("\nMonthly expenses: $%.2f", monthly_expenses);
    printf("\nMonthly savings: $%.2f", savings);

    return 0;
}

/* Function definitions */
float calculate_total_income(float monthly_salary, float monthly_bonus) {
    return monthly_salary + monthly_bonus;
}

float calculate_monthly_expenses(float rent, float utilities, float groceries, float transportation, float misc) {
    return rent + utilities + groceries + transportation + misc;
}

float calculate_savings(float total_income, float monthly_expenses) {
    return total_income - monthly_expenses;
}