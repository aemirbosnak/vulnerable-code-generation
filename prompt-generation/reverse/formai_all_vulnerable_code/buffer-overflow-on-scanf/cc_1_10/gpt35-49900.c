//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double calculate_total_income(double[], int);
double calculate_total_expenses(double[], int);
double calculate_net_savings(double, double);
double calculate_average_expenses(double[], int);

int main() {
    int num_months;
    printf("Enter the number of months to plan for: ");
    scanf("%d", &num_months);

    // Dynamic memory allocation for expense and income arrays
    double *expenses = (double*) malloc(num_months * sizeof(double));
    double *income = (double*) malloc(num_months * sizeof(double));

    // Loop to input expense and income amounts for each month
    for (int i = 0; i < num_months; i++) {
        printf("\nMonth %d:\n", i+1);
        printf("Enter total income for the month: $");
        scanf("%lf", &income[i]);
        printf("Enter total expenses for the month: $");
        scanf("%lf", &expenses[i]);
    }

    // Calculate total income and expenses
    double total_income = calculate_total_income(income, num_months);
    double total_expenses = calculate_total_expenses(expenses, num_months);

    // Calculate net savings
    double net_savings = calculate_net_savings(total_income, total_expenses);

    // Calculate average monthly expenses
    double average_expenses = calculate_average_expenses(expenses, num_months);

    // Output results
    printf("\n\n=======PERSONAL FINANCE PLANNER REPORT=======\n");
    printf("Total Income: $%.2lf\n", total_income);
    printf("Total Expenses: $%.2lf\n", total_expenses);
    printf("Net Savings: $%.2lf\n", net_savings);
    printf("Average Monthly Expenses: $%.2lf\n", average_expenses);

    free(expenses);
    free(income);

    return 0;
}

/**
 * Function to calculate total income over a given period of time
 * @param arr Income array
 * @param n Number of months to calculate income for
 * @return Total income over the period
 */
double calculate_total_income(double arr[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

/**
 * Function to calculate total expenses over a given period of time
 * @param arr Expense array
 * @param n Number of months to calculate expenses for
 * @return Total expenses over the period
 */
double calculate_total_expenses(double arr[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

/**
 * Function to calculate net savings over a given period of time
 * @param income Total income over the period
 * @param expenses Total expenses over the period
 * @return Net savings over the period
 */
double calculate_net_savings(double income, double expenses) {
    return income - expenses;
}

/**
 * Function to calculate average monthly expenses over a given period of time
 * @param arr Expense array
 * @param n Number of months to calculate expenses for
 * @return Average monthly expenses over the period
 */
double calculate_average_expenses(double arr[], int n) {
    double total = calculate_total_expenses(arr, n);
    return total / n;
}