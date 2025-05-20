//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
//Personal Finance Planner Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to calculate monthly expenses
int calculateMonthlyExpenses(int income) {
    //Set up monthly expenses as 75% of income
    int expenses = 0.75 * income;
    return expenses;
}

//Function to calculate monthly savings
int calculateMonthlySavings(int income, int expenses) {
    //Set up monthly savings as the difference between income and expenses
    int savings = income - expenses;
    return savings;
}

//Function to calculate yearly savings
int calculateYearlySavings(int income, int expenses) {
    //Set up yearly savings as the sum of monthly savings over 12 months
    int yearlySavings = 0;
    for (int i = 1; i <= 12; i++) {
        yearlySavings += calculateMonthlySavings(income, expenses);
    }
    return yearlySavings;
}

int main() {
    //Input income and expenses
    int income;
    printf("Enter your monthly income: ");
    scanf("%d", &income);
    int expenses;
    printf("Enter your monthly expenses: ");
    scanf("%d", &expenses);

    //Calculate monthly expenses and savings
    int monthlyExpenses = calculateMonthlyExpenses(income);
    int monthlySavings = calculateMonthlySavings(income, expenses);

    //Calculate yearly savings
    int yearlySavings = calculateYearlySavings(income, expenses);

    //Output results
    printf("Monthly Expenses: $%d\n", monthlyExpenses);
    printf("Monthly Savings: $%d\n", monthlySavings);
    printf("Yearly Savings: $%d\n", yearlySavings);

    return 0;
}