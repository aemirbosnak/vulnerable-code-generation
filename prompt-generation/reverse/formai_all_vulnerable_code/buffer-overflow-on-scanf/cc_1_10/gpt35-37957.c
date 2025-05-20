//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>

// Function to calculate total expenses
float totalExpenses(float expenses[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += expenses[i];
    }
    return total;
}

// Function to calculate monthly savings
float monthlySavings(float income, float expenses) {
    return income - expenses;
}

int main() {
    // Variables
    float income, savings, expenses[12];
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Input annual income
    printf("Enter your annual income: ");
    scanf("%f", &income);

    // Input monthly expenses
    printf("Enter your monthly expenses for each month:\n");
    for(int i = 0; i < 12; i++) {
        printf("%s: ", months[i]);
        scanf("%f", &expenses[i]);
    }

    // Calculate total expenses
    float totalExp = totalExpenses(expenses, 12);

    // Calculate monthly savings
    float monthlySave = monthlySavings(income/12, totalExp/12);

    // Calculate savings rate
    float savingsRate = (monthlySave / (income/12)) * 100;

    // Output results
    printf("\n===========RESULTS===========\n");
    printf("Annual Income:\t\t$%.2f\n", income);
    printf("Total Expenses:\t\t$%.2f\n", totalExp);
    printf("Monthly Savings:\t$%.2f\n", monthlySave);
    printf("Savings Rate:\t\t%.2f%%\n", savingsRate);

    return 0;
}