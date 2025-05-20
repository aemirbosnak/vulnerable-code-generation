//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>

// Function to calculate total expenses
float calculateExpenses(int numExpenses, float expenses[]) {
    float totalExpenses = 0;
    for(int i=0; i<numExpenses; i++) {
        totalExpenses += expenses[i];
    }
    return totalExpenses;
}

// Function to calculate total income
float calculateIncome(int numIncomes, float incomes[]) {
    float totalIncome = 0;
    for(int i=0; i<numIncomes; i++) {
        totalIncome += incomes[i];
    }
    return totalIncome;
}

// Function to calculate savings
float calculateSavings(float expenses, float income) {
    float savings = income - expenses;
    return savings;
}

int main() {
    // Get user inputs for expenses
    printf("How many expenses would you like to enter? ");
    int nExpenses;
    scanf("%d", &nExpenses);
    float expenses[nExpenses];
    for(int i=0; i<nExpenses; i++) {
        printf("Enter expense #%d: ", i+1);
        scanf("%f", &expenses[i]);
    }

    // Get user inputs for income
    printf("How many sources of income would you like to enter? ");
    int nIncomes;
    scanf("%d", &nIncomes);
    float incomes[nIncomes];
    for(int i=0; i<nIncomes; i++) {
        printf("Enter income source #%d: ", i+1);
        scanf("%f", &incomes[i]);
    }

    // Calculate and display total expenses, total income, and savings
    float totalExpenses = calculateExpenses(nExpenses, expenses);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    float totalIncome = calculateIncome(nIncomes, incomes);
    printf("Total Income: $%.2f\n", totalIncome);
    float savings = calculateSavings(totalExpenses, totalIncome);
    if(savings >= 0) {
        printf("You have a surplus of $%.2f in your budget.\n", savings);
    } else {
        printf("You have a deficit of $%.2f in your budget.\n", savings);
    }

    return 0;
}