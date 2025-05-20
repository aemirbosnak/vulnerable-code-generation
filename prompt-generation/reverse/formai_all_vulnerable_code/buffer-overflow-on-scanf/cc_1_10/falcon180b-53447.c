//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for personal finance planner
typedef struct {
    char name[50];
    float income;
    float expenses[10];
    float savings;
} PersonalFinance;

// Function to calculate total expenses
float calculateTotalExpenses(PersonalFinance pf) {
    float totalExpenses = 0.0;
    for (int i = 0; i < 10; i++) {
        totalExpenses += pf.expenses[i];
    }
    return totalExpenses;
}

// Function to calculate savings percentage
float calculateSavingsPercentage(PersonalFinance pf) {
    float savingsPercentage = ((pf.savings / pf.income) * 100);
    return savingsPercentage;
}

// Function to print personal finance details
void printPersonalFinance(PersonalFinance pf) {
    printf("Name: %s\n", pf.name);
    printf("Income: $%.2f\n", pf.income);
    printf("Expenses:\n");
    for (int i = 0; i < 10; i++) {
        printf(" - $%.2f\n", pf.expenses[i]);
    }
    printf("Savings: $%.2f\n", pf.savings);
    printf("Savings Percentage: %.2f%%\n", calculateSavingsPercentage(pf));
}

// Main function
int main() {
    PersonalFinance pf;

    // Get user input for name
    printf("Enter your name: ");
    scanf("%s", pf.name);

    // Get user input for income
    printf("Enter your income: $");
    scanf("%f", &pf.income);

    // Get user input for expenses
    for (int i = 0; i < 10; i++) {
        printf("Enter expense %d: $", i + 1);
        scanf("%f", &pf.expenses[i]);
    }

    // Calculate total expenses and savings percentage
    float totalExpenses = calculateTotalExpenses(pf);
    float savingsPercentage = calculateSavingsPercentage(pf);

    // Print personal finance details
    printf("\nPersonal Finance Details:\n");
    printPersonalFinance(pf);

    // Print additional analysis based on savings percentage
    if (savingsPercentage >= 30.0) {
        printf("\nCongratulations! You are saving at least 30% of your income.\n");
    } else if (savingsPercentage >= 20.0) {
        printf("\nGood job! You are saving at least 20% of your income.\n");
    } else {
        printf("\nYou may want to consider increasing your savings.\n");
    }

    return 0;
}