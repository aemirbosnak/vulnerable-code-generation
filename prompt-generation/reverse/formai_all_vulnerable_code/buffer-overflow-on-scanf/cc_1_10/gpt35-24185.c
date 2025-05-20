//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>

// function to calculate total expenses
float calculate_expenses(float *expenses, int size) {
    float total = 0;
    for(int i=0; i<size; i++) {
        total += expenses[i];
    }
    return total;
}

// function to calculate total income
float calculate_income(float *income, int size) {
    float total = 0;
    for(int i=0; i<size; i++) {
        total += income[i];
    }
    return total;
}

int main() {

    // declare variables
    float income[12], expenses[12];
    float total_income, total_expenses, balance;

    // prompt user to input monthly income
    printf("Enter your monthly income for the past 12 months\n");
    for(int i=0; i<12; i++) {
        printf("Month %d: ", i+1);
        scanf("%f", &income[i]);
    }

    // prompt user to input monthly expenses
    printf("Enter your monthly expenses for the past 12 months\n");
    for(int i=0; i<12; i++) {
        printf("Month %d: ", i+1);
        scanf("%f", &expenses[i]);
    }

    // calculate total income and expenses
    total_income = calculate_income(income, 12);
    total_expenses = calculate_expenses(expenses, 12);

    // calculate balance
    balance = total_income - total_expenses;

    // display results
    printf("Total income: $%.2f\n", total_income);
    printf("Total expenses: $%.2f\n", total_expenses);
    printf("Balance: $%.2f\n", balance);

    // determine whether balance is positive or negative
    if(balance > 0) {
        printf("Congrats, you have a positive balance!\n");
    } else if(balance < 0) {
        printf("Uh oh, you have a negative balance. It might be time to start budgeting.\n");
    } else {
        printf("Your income and expenses are equal. You are living within your means!\n");
    }

    return 0;
}