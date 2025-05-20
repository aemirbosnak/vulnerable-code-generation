//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double salary;
    double expenses;
    double savings;
} PersonalFinance;

PersonalFinance createPersonalFinance(double salary, double expenses, double savings) {
    PersonalFinance finance;
    finance.salary = salary;
    finance.expenses = expenses;
    finance.savings = savings;
    return finance;
}

void printPersonalFinance(PersonalFinance finance) {
    printf("Salary: $%.2f\n", finance.salary);
    printf("Monthly Expenses: $%.2f\n", finance.expenses);
    printf("Monthly Savings: $%.2f\n", finance.savings);
}

void calculateSavingsGoals(PersonalFinance finance, int years) {
    double totalSavings = finance.savings * 12 * years;
    printf("Total Savings in %d years: $%.2f\n", years, totalSavings);

    double investmentEarnings = (totalSavings * 0.05) * years;
    printf("Potential Investment Earnings (5%% yearly return): $%.2f\n", investmentEarnings);

    double retirementSavingsGoal = finance.salary * 12 * 25;
    printf("Retirement Savings Goal (25 times annual salary): $%.2f\n", retirementSavingsGoal);

    if (totalSavings >= retirementSavingsGoal) {
        printf("Congratulations! You have reached your retirement savings goal.\n");
    } else {
        double remainingSavings = retirementSavingsGoal - totalSavings;
        printf("You are $%.2f away from reaching your retirement savings goal.\n", remainingSavings);
        double yearsUntilRetirement = remainingSavings / (finance.salary * 12);
        printf("At your current savings rate, you will reach your retirement savings goal in %.1f years.\n", yearsUntilRetirement);
    }
}

int main() {
    double salary, expenses, savings;
    printf("Enter your monthly salary: $");
    scanf("%lf", &salary);
    printf("Enter your monthly expenses: $");
    scanf("%lf", &expenses);
    printf("Enter your monthly savings: $");
    scanf("%lf", &savings);

    PersonalFinance finance = createPersonalFinance(salary, expenses, savings);
    printf("\nYour Personal Finances:\n");
    printPersonalFinance(finance);

    int years;
    printf("\nEnter a number of years to calculate savings goals: ");
    scanf("%d", &years);

    printf("\nSavings Goals for %d years:\n", years);
    calculateSavingsGoals(finance, years);

    return 0;
}