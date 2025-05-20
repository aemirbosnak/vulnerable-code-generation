//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
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
} PersonalFinancePlanner;

// Function to calculate the total net worth of a personal finance planner
double calculateTotalNetWorth(PersonalFinancePlanner planner) {
    double totalNetWorth = planner.savings + planner.investments - planner.expenses;
    return totalNetWorth;
}

// Function to calculate the monthly savings of a personal finance planner
double calculateMonthlySavings(PersonalFinancePlanner planner) {
    double monthlySavings = planner.income * 0.1;
    return monthlySavings;
}

// Function to calculate the monthly investments of a personal finance planner
double calculateMonthlyInvestments(PersonalFinancePlanner planner) {
    double monthlyInvestments = planner.income * 0.2;
    return monthlyInvestments;
}

int main() {
    // Create a Personal Finance Planner structure
    PersonalFinancePlanner planner;

    // Get the planner's name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    // Calculate the planner's total net worth
    planner.savings = calculateMonthlySavings(planner);
    planner.investments = calculateMonthlyInvestments(planner);
    double totalNetWorth = calculateTotalNetWorth(planner);

    // Print the planner's total net worth
    printf("Your total net worth is: $%.2lf", totalNetWorth);

    return 0;
}