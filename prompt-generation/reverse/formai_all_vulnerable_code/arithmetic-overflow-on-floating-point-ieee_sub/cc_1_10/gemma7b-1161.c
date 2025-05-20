//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the Personal Finance Planner structure
typedef struct PersonalFinancePlanner {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
} PersonalFinancePlanner;

// Function to calculate the total assets
double calculateTotalAssets(PersonalFinancePlanner *planner) {
    return planner->savings + planner->investments;
}

// Function to calculate the total liabilities
double calculateTotalLiabilities(PersonalFinancePlanner *planner) {
    return planner->expenses;
}

// Function to calculate the net worth
double calculateNetWorth(PersonalFinancePlanner *planner) {
    return calculateTotalAssets(planner) - calculateTotalLiabilities(planner);
}

int main() {
    // Create a personal finance planner
    PersonalFinancePlanner planner;

    // Get the planner's name, age, income, expenses, savings, and investments
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

    // Calculate the total assets, total liabilities, and net worth
    double totalAssets = calculateTotalAssets(&planner);
    double totalLiabilities = calculateTotalLiabilities(&planner);
    double netWorth = calculateNetWorth(&planner);

    // Print the results
    printf("Total Assets: $%.2lf\n", totalAssets);
    printf("Total Liabilities: $%.2lf\n", totalLiabilities);
    printf("Net Worth: $%.2lf\n", netWorth);

    return 0;
}