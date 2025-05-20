//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function to calculate net worth
float calcNetWorth(float assets[], float liabilities[], int n) {
    float netWorth = 0;
    for(int i = 0; i < n; i++) {
        netWorth += assets[i];
        netWorth -= liabilities[i];
    }
    return netWorth;
}

// Function to calculate monthly expenses
float calcMonthlyExpenses(float expenses[], int n) {
    float monthlyExpenses = 0;
    for(int i = 0; i < n; i++) {
        monthlyExpenses += expenses[i];
    }
    return monthlyExpenses;
}

int main() {
    int n;

    // Taking Input
    printf("Enter the number of assets and liabilities: ");
    scanf("%d", &n);

    float assets[n], liabilities[n], expenses[n];

    printf("Enter the value of assets:\n");
    for(int i = 0; i < n; i++) {
        printf("Asset %d: ", i + 1);
        scanf("%f", &assets[i]);
    }

    printf("Enter the value of liabilities:\n");
    for(int i = 0; i < n; i++) {
        printf("Liability %d: ", i + 1);
        scanf("%f", &liabilities[i]);
    }

    printf("Enter the value of monthly expenses:\n");
    for(int i = 0; i < n; i++) {
        printf("Expense %d: ", i + 1);
        scanf("%f", &expenses[i]);
    }

    // Calculating net worth and monthly expenses
    float netWorth = calcNetWorth(assets, liabilities, n);
    float monthlyExpenses = calcMonthlyExpenses(expenses, n);

    // Output
    printf("Your net worth is: $%.2f\n", netWorth);
    printf("Your monthly expenses are: $%.2f\n", monthlyExpenses);

    // Buying decision
    if(netWorth <= 0) {
        printf("WARNING: You are in debt.\n");
    }
    else {
        if(monthlyExpenses > (0.5 * netWorth)) {
            printf("WARNING: You need to cut down on your expenses.\n");
        }
        else if(monthlyExpenses <= (0.25 * netWorth)) {
            printf("You can afford to buy a new car!\n");
        }
        else {
            printf("You cannot afford to buy a new car right now, but you can start saving for it.\n");
        }
    }

    return 0;
}