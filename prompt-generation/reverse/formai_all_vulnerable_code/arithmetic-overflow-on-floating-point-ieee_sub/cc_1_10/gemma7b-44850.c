//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Personal Finance Planner structure
typedef struct PersonalFinancePlanner {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
    double debt;
} PersonalFinancePlanner;

// Function to calculate the total net worth of a person
double calculateTotalNetWorth(PersonalFinancePlanner *planner) {
    double totalNetWorth = planner->savings + planner->investments - planner->debt;
    return totalNetWorth;
}

// Function to calculate the monthly savings of a person
double calculateMonthlySavings(PersonalFinancePlanner *planner) {
    double monthlySavings = planner->income - planner->expenses;
    return monthlySavings;
}

// Function to calculate the return on investment of a person
double calculateReturnOnInvestment(PersonalFinancePlanner *planner) {
    double returnOnInvestment = (planner->investments * 0.06) / planner->savings;
    return returnOnInvestment;
}

int main() {
    // Create a personal finance planner structure
    PersonalFinancePlanner planner;

    // Get the person's name, age, income, expenses, savings, investments, and debt
    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    printf("Enter your savings: ");
    scanf("%lf", &planner.savings);

    printf("Enter your investments: ");
    scanf("%lf", &planner.investments);

    printf("Enter your debt: ");
    scanf("%lf", &planner.debt);

    // Calculate the total net worth, monthly savings, and return on investment
    double totalNetWorth = calculateTotalNetWorth(&planner);
    double monthlySavings = calculateMonthlySavings(&planner);
    double returnOnInvestment = calculateReturnOnInvestment(&planner);

    // Print the results
    printf("Total net worth: $%.2lf", totalNetWorth);

    printf("\nMonthly savings: $%.2lf", monthlySavings);

    printf("\nReturn on investment: %.2f%%", returnOnInvestment);

    return 0;
}