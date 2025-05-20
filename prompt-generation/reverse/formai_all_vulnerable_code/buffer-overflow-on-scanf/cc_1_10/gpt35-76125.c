//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>

int main() {
    float income, savings, expenses, misc_expense, emergency_fund, debt_total;

    // get user input
    printf("Enter your monthly income: ");
    scanf("%f", &income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    printf("Enter your monthly savings goal: ");
    scanf("%f", &savings);

    printf("Enter your miscellaneous expenses: ");
    scanf("%f", &misc_expense);

    printf("Enter your current emergency fund amount: ");
    scanf("%f", &emergency_fund);

    printf("Enter your total debt amount: ");
    scanf("%f", &debt_total);

    // calculate savings rate and check emergency fund status
    float savings_rate = (savings / income) * 100;
    printf("Your savings rate is %f%%\n", savings_rate);

    if (emergency_fund < expenses * 3) {
        printf("Your emergency fund needs to be increased!\n");
    } else {
        printf("Your emergency fund is sufficient.\n");
    }

    // calculate debt-to-income ratio and give advice
    float dti = (debt_total / income) * 100;
    printf("Your debt-to-income ratio is %f%%\n", dti);

    if (dti > 50) {
        printf("You may need to reevaluate your debt repayment plan.\n");
    } else {
        printf("Your debt-to-income ratio is healthy.\n");
    }

    // calculate discretionary income and give spending advice
    float discretionary_income = income - expenses - savings;
    if (discretionary_income > misc_expense) {
        printf("You have enough funds for miscellaneous expenses.\n");
    } else {
        printf("You may need to limit your discretionary spending.\n");
    }

    return 0;
}