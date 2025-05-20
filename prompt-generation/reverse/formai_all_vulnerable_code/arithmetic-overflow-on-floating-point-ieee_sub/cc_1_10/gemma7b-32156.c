//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complete
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
    char occupation[50];
} PersonalFinancePlanner;

// Function to calculate the total amount of savings and investments
double calculateTotalSavingsAndInvestments(PersonalFinancePlanner *planner) {
    return planner->savings + planner->investments;
}

// Function to calculate the monthly expenses
double calculateMonthlyExpenses(PersonalFinancePlanner *planner) {
    return planner->expenses / 12;
}

// Function to calculate the monthly savings
double calculateMonthlySavings(PersonalFinancePlanner *planner) {
    return planner->income - calculateMonthlyExpenses(planner) - calculateTotalSavingsAndInvestments(planner);
}

int main() {
    // Create a Personal Finance Planner structure
    PersonalFinancePlanner planner;

    // Get the planner's name, age, and occupation
    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your occupation: ");
    scanf("%s", planner.occupation);

    // Get the planner's income, expenses, and savings
    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    printf("Enter your savings: ");
    scanf("%lf", &planner.savings);

    // Calculate the monthly savings
    double monthlySavings = calculateMonthlySavings(&planner);

    // Print the monthly savings
    printf("Your monthly savings are: $%.2lf", monthlySavings);

    return 0;
}