//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
// Personal Finance Planner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
const double INTEREST_RATE = 0.05;
const int NUM_MONTHS = 12;

// Structures
typedef struct {
    double income;
    double expenses;
    double savings;
    double debt;
    double credit;
} FinancialState;

// Functions
double calculateInterest(double principal, double rate, int months) {
    return principal * pow((1 + rate), months);
}

FinancialState calculateFinancialState(double income, double expenses, double savings, double debt, double credit) {
    FinancialState state;
    state.income = income;
    state.expenses = expenses;
    state.savings = savings;
    state.debt = debt;
    state.credit = credit;
    return state;
}

void displayFinancialState(FinancialState state) {
    printf("Income: $%.2f\n", state.income);
    printf("Expenses: $%.2f\n", state.expenses);
    printf("Savings: $%.2f\n", state.savings);
    printf("Debt: $%.2f\n", state.debt);
    printf("Credit: $%.2f\n", state.credit);
}

int main() {
    double income = 5000;
    double expenses = 2000;
    double savings = 1000;
    double debt = 5000;
    double credit = 1000;

    FinancialState state = calculateFinancialState(income, expenses, savings, debt, credit);
    displayFinancialState(state);

    double interest = calculateInterest(debt, INTEREST_RATE, NUM_MONTHS);
    printf("Interest: $%.2f\n", interest);

    double principal = debt - interest;
    printf("Principal: $%.2f\n", principal);

    double newDebt = debt - principal;
    printf("New Debt: $%.2f\n", newDebt);

    double newCredit = credit + interest;
    printf("New Credit: $%.2f\n", newCredit);

    return 0;
}