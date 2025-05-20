//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to calculate total expenses
float calculateExpenses(float *arr, int num) {
    float expenses = 0.0;
    for(int i = 0; i < num; i++) {
        expenses += *(arr+i);
    }
    return expenses;
}

/* The following function demonstrates the C Personal Finance Planner. 
It takes the user's monthly income and expenses and calculates the net income. 
If the net income is positive, it suggests the user to save some money. 
If the net income is negative, it suggests the user to reduce their expenses. */

int main() {
    printf("\n\tWelcome to C Personal Finance Planner\n");

    float income, expenses, balance = 0.0;
    int numExpenses;

    printf("\nEnter your monthly income: $");
    scanf("%f", &income);

    printf("\nHow many monthly expenses do you have? ");
    scanf("%d", &numExpenses);

    float *monthlyExpenses = (float*) malloc(numExpenses * sizeof(float));
    for(int i = 0; i < numExpenses; i++) {
        printf("\nEnter expense #%d: $", i+1);
        scanf("%f", monthlyExpenses+i);
    }

    expenses = calculateExpenses(monthlyExpenses, numExpenses);
    balance = income - expenses;
    printf("\nYour monthly income is: $%.2f\n", income);
    printf("\nYour monthly expenses are: $%.2f\n", expenses);
    printf("\nYour net income is: $%.2f\n", balance);

    if(balance > 0) {
        printf("\nYou have extra money this month. Consider saving some of it.\n");
    } else if(balance == 0) {
        printf("\nYour income and expenses are balanced. Keep up the good work!\n");
    } else {
        printf("\nYour expenses exceed your income. Please reduce your expenses.\n");
    }

    free(monthlyExpenses);
    return 0;
}