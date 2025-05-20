//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>

// function to calculate monthly expenses
double calculateMonthlyExpenses(double rent, double utilities, double groceries, double transportation, double entertainment) {
    double totalExpenses = rent + utilities + groceries + transportation + entertainment;
    double monthlyExpenses = totalExpenses / 12.0;
    return monthlyExpenses;
}

// function to calculate monthly income
double calculateMonthlyIncome(double salary, double investments) {
    double totalIncome = salary + investments;
    double monthlyIncome = totalIncome / 12.0;
    return monthlyIncome;
}

// function to calculate monthly savings
double calculateMonthlySavings(double monthlyIncome, double monthlyExpenses) {
    double monthlySavings = monthlyIncome - monthlyExpenses;
    return monthlySavings;
}

// function to display financial summary
void displayFinancialSummary(double monthlyIncome, double monthlyExpenses, double monthlySavings) {
    printf("\nFinancial Summary: \n");
    printf("Monthly Income: $%.2f\n", monthlyIncome);
    printf("Monthly Expenses: $%.2f\n", monthlyExpenses);
    printf("Monthly Savings: $%.2f\n", monthlySavings);
}

int main() {
    double rent, utilities, groceries, transportation, entertainment, salary, investments;
    double monthlyExpenses, monthlyIncome, monthlySavings;

    printf("Enter your monthly rent: $");
    scanf("%lf", &rent);

    printf("Enter your monthly utilities: $");
    scanf("%lf", &utilities);

    printf("Enter your monthly groceries: $");
    scanf("%lf", &groceries);

    printf("Enter your monthly transportation costs: $");
    scanf("%lf", &transportation);

    printf("Enter your monthly entertainment expenses: $");
    scanf("%lf", &entertainment);

    printf("Enter your monthly salary: $");
    scanf("%lf", &salary);

    printf("Enter your monthly investment income: $");
    scanf("%lf", &investments);

    // calculate financial information
    monthlyExpenses = calculateMonthlyExpenses(rent, utilities, groceries, transportation, entertainment);
    monthlyIncome = calculateMonthlyIncome(salary, investments);
    monthlySavings = calculateMonthlySavings(monthlyIncome, monthlyExpenses);

    // display financial summary
    displayFinancialSummary(monthlyIncome, monthlyExpenses, monthlySavings);

    return 0;
}