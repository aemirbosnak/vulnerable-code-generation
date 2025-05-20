//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of items
#define MONTHS 12 // Number of months in a year

struct expense {
    int month;
    float amount;
};

int main() {
    struct expense expenses[MAX];
    float totalExpenses = 0, averageMonthlyExpense;
    int numExpenses = 0, i, j, month;
    
    char choice;
    do {
        printf("\nEnter the month (1-12): ");
        scanf("%d", &month);
        printf("Enter the expense amount: $");
        scanf("%f", &expenses[numExpenses].amount);
        expenses[numExpenses].month = month;
        numExpenses++;

        printf("\nDo you want to enter another expense (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Calculate total expenses
    for (i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }

    // Calculate average monthly expenses
    averageMonthlyExpense = totalExpenses / MONTHS;

    // Display monthly expenses
    printf("\nMonthly Expenses:\n");
    for (i = 1; i <= MONTHS; i++) {
        printf("Month %d: $", i);
        float monthlyTotal = 0;
        int numExpensesInMonth = 0;

        // Calculate total expenses for each month
        for (j = 0; j < numExpenses; j++) {
            if (expenses[j].month == i) {
                monthlyTotal += expenses[j].amount;
                numExpensesInMonth++;
            }
        }

        if (numExpensesInMonth > 0) {
            printf("%.2f\n", monthlyTotal);
        } else {
            printf("0.00\n");
        }
    }

    // Display total expenses and average monthly expense
    printf("\nTotal Expenses: $%.2f\n", totalExpenses);
    printf("Average Monthly Expense: $%.2f\n", averageMonthlyExpense);

    return 0;
}