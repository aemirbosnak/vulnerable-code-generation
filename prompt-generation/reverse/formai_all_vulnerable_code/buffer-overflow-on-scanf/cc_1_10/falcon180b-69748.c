//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define global variables */
double income;
double expenses[10];
double savings;
int numExpenses;

/* Function to add an expense */
void addExpense(double amount) {
    if (numExpenses < 10) {
        expenses[numExpenses] = amount;
        numExpenses++;
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}

/* Function to calculate total expenses */
double calcTotalExpenses() {
    double total = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i];
    }
    return total;
}

/* Function to calculate savings */
double calcSavings() {
    return income - calcTotalExpenses();
}

/* Function to display personal finance summary */
void displaySummary() {
    printf("Personal Finance Summary:\n");
    printf("Income: $%.2f\n", income);
    printf("Total Expenses: $%.2f\n", calcTotalExpenses());
    printf("Savings: $%.2f\n", calcSavings());
}

/* Main function */
int main() {
    /* Initialize global variables */
    income = 0.0;
    numExpenses = 0;
    savings = 0.0;

    /* Prompt user for income */
    printf("Enter your monthly income: ");
    scanf("%lf", &income);

    /* Prompt user for expenses */
    while (numExpenses < 10) {
        printf("Enter an expense (or 0 to finish): ");
        scanf("%lf", &expenses[numExpenses]);
        if (expenses[numExpenses] == 0.0) {
            break;
        }
        numExpenses++;
    }

    /* Calculate and display personal finance summary */
    displaySummary();

    return 0;
}