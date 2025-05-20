//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include<stdio.h>
#include<stdlib.h>

// Struct to store Personal Finance Details
struct finance {
    float income;
    float expenses;
    float savings;
};

// Function to get Finance Details
void getFinanceDetails(struct finance *f) {
    printf("Enter Your Monthly Income: ");
    scanf("%f", &(f->income));

    printf("Enter Your Monthly Expenses: ");
    scanf("%f", &(f->expenses));
}

// Function to Calculate Savings
void calculateSavings(struct finance *f) {
    f->savings = f->income - f->expenses;
}

// Function to display Finance Details
void displayFinanceDetails(struct finance f) {
    printf("\nMonthly Income     : $%.2f", f.income);
    printf("\nMonthly Expenses   : $%.2f", f.expenses);
    printf("\nMonthly Savings    : $%.2f", f.savings);

    if (f.savings > 0) {
        printf("\nCongratulations! You have saved $%.2f this month.\n", f.savings);
    } else {
        printf("\nLooks like you have spent more than you earned this month. Don't worry, you can always do better next time. Keep going!\n");
    }
}

int main() {
    struct finance f;

    printf("********** Welcome to Personal Finance Planner **********\n");

    getFinanceDetails(&f);
    calculateSavings(&f);
    displayFinanceDetails(f);

    printf("\nThank You for using Personal Finance Planner. Have a happy day!\n");

    return 0;
}