//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>

// Function to calculate the total income
float totalIncome(float salary, float bonus) {
    return salary + bonus;
}

// Function to calculate the total expenses
float totalExpenses(float rent, float utilities, float groceries, float transportation, float otherExpenses) {
    return rent + utilities + groceries + transportation + otherExpenses;
}

int main() {
    // Declare variables
    float salary, bonus, rent, utilities, groceries, transportation, otherExpenses;
    float totalIncomeVar, totalExpensesVar, savings;

    // Get user input
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly bonus: ");
    scanf("%f", &bonus);

    printf("Enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Enter your monthly utilities bill: ");
    scanf("%f", &utilities);

    printf("Enter your monthly grocery bill: ");
    scanf("%f", &groceries);

    printf("Enter your monthly transportation expense: ");
    scanf("%f", &transportation);

    printf("Enter your other monthly expenses: ");
    scanf("%f", &otherExpenses);

    // Calculate the total income and expenses
    totalIncomeVar = totalIncome(salary, bonus);
    totalExpensesVar = totalExpenses(rent, utilities, groceries, transportation, otherExpenses);

    // Calculate the savings
    savings = totalIncomeVar - totalExpensesVar;

    // Print the results
    printf("\nTotal Income: %.2f\n", totalIncomeVar);
    printf("Total Expenses: %.2f\n", totalExpensesVar);
    printf("Savings: %.2f\n", savings);

    return 0;
}